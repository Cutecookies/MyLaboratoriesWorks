# include "libs/data_structures/flow/flow.h"
# include "libs/data_structures/string_/string_.h"
# include "stdio.h"
# include <stdlib.h>
# include <assert.h>

void test_transposeAllMatricesInFile() {
    char filename[] = "D:/text_lab_19.txt";
    createFileWithMatrices(filename);
    transposeAllMatricesInFile(filename);
    int amt_m;
    matrix *matrices = readMatrices(filename, &amt_m);

    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 4, 7,
                    2, 5, 8,
                    3, 6, 9,
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 11,
                    8, 16,
            },
            2, 2
    );
    matrix m3 = createMatrixFromArray(
            (int[]) {
                    3,
            },
            1, 1
    );

    assert(areTwoMatricesEqual(&m1, &matrices[0]));
    assert(areTwoMatricesEqual(&m2, &matrices[1]));
    assert(areTwoMatricesEqual(&m3, &matrices[2]));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
    freeMemMatrix(&m3);
    freeMemMatrices(matrices, 3);
    free(matrices);
}

void test_convertNumbersToFloatingPoint() {
    char filename[] = "D:/text_lab_19.txt";
    createFileWithFloatNumbers(filename);
    convertNumbersToFloatingPoint(filename);
    float exp[] = {1.23e+02, 4.83e+03, 1.43e+00, 4.23e+02, 3.40e-01, 2.30e-04};
    FILE *file = fopen(filename, "r");
    float x;
    for (int i = 0; i < 6; i++) {
        fscanf(file, "%f", &x);
        assert(x == exp[i]);
    }
    fclose(file);
}

// 1 операнд
void test_solveExample_1Operand() {
    char filename[] = "D:/text_lab_19.txt";

    float operands[] = {12.5};
    char operations[] = {};
    int amt_op = 0;
    writeOperation(filename, operands, operations, amt_op);

    solveExample(filename);

    FILE *file2 = fopen(filename, "r");
    char operation[100];
    fgets(operation, 100, file2);
    float get;
    fscanf(file2, "%f", &get);
    fclose(file2);

    assert(get == 12.5);
}

// 2 операнда
void test_solveExample_2Operands() {
    char filename[] = "D:/text_lab_19.txt";

    float operands[2] = {7.5, 2.0};
    char operations[1] = {'*'};
    int amt_op = 1;
    writeOperation(filename, operands, operations, amt_op);

    solveExample(filename);

    FILE *file2 = fopen(filename, "r");
    char operation[100];
    fgets(operation, 100, file2);
    float get;
    fscanf(file2, "%f", &get);
    fclose(file2);

    assert(get == 15);
}

// 3 операнда
void test_solveExample_3Operands() {
    char filename[] = "D:/text_lab_19.txt";

    float operands[3] = {7.5, 2.0, 5.5};
    char operations[2] = {'*', '-'};
    int amt_op = 2;
    writeOperation(filename, operands, operations, amt_op);

    solveExample(filename);

    FILE *file2 = fopen(filename, "r");
    char operation[100];
    fgets(operation, 100, file2);
    float get;
    fscanf(file2, "%f", &get);
    fclose(file2);

    assert(get == 9.5);
}

// умножение на втором месте
void test_solveExample_multiplicationIn2Place() {
    char filename[] = "D:/text_lab_19.txt";

    float operands[3] = {7.5, 5.5, 2.0};
    char operations[2] = {'-', '*'};
    int amt_op = 2;
    writeOperation(filename, operands, operations, amt_op);

    solveExample(filename);

    FILE *file2 = fopen(filename, "r");
    char operation[100];
    fgets(operation, 100, file2);
    float get;
    fscanf(file2, "%f", &get);
    fclose(file2);

    assert(get == -3.5);
}

void test_leftWordsWithSymbols() {
    char filename[] = "D:/text_lab_19.txt";
    char symbols[] = "ab";
    char words[100][100] = {"dog", "cat", "abroad", "interesting", "laboratory"};

    writeWordsInFile(filename, words, 5);

    leftWordsWithSymbols(filename, symbols);

    FILE *file = fopen(filename, "r");

    char res[100];
    fgets(res, 100, file);

    fclose(file);

    char exp[100] = "abroad laboratory";

    assert(compareStr(res, exp, 17) == 1);
}

void test_onlyLongWords() {
    char filename[] = "D:/text_lab_19.txt";
    FILE *file = fopen(filename, "w");
    fprintf(file, "%s\n", "cat dog elephant");
    fprintf(file, "%s\n", "tiger dog elephant");
    fprintf(file, "%s", "cat crocodile horse");
    fclose(file);

    onlyLongWords(filename);

    char *word1_exp = "elephant";
    char *word2_exp = "crocodile";
    FILE *file2 = fopen(filename, "r");
    char *word1_res = malloc(sizeof(char) * 100);
    char *word2_res = malloc(sizeof(char) * 100);
    char *word3_res = malloc(sizeof(char) * 100);
    fgets(word1_res, 100, file2);
    fgets(word2_res, 100, file2);
    fgets(word3_res, 100, file2);

    assert(compareStr(word1_res, word1_exp, 8));
    assert(compareStr(word2_res, word1_exp, 8));
    assert(compareStr(word3_res, word2_exp, 9));

    fclose(file2);

    free(word1_res);
    free(word2_res);
    free(word3_res);
}

void test_onlyPolynomialWithoutRootX() {
    char filename[] = "D:/text_lab_19.txt";
    int amt_args = 2;
    int degrees[] = {2, 0};
    double coefficients[] = {1, -1};
    Polynomial p1 = createPolynomialFromArray(degrees, coefficients, amt_args);

    amt_args = 3;
    int degrees2[] = {4, 3, 0};
    double coefficients2[] = {3, -4, -1};
    Polynomial p2 = createPolynomialFromArray(degrees2, coefficients2, amt_args);

    amt_args = 1;
    int degrees3[] = {0};
    double coefficients3[] = {2};
    Polynomial p3 = createPolynomialFromArray(degrees3, coefficients3, amt_args);

    Polynomial ps[] = {p1, p2, p3};

    FILE *file = fopen(filename, "wb");
    writePolynomialsToFile(ps, file, 3);
    fclose(file);

    onlyPolynomialWithoutRootX(filename, 1);

    int amt_ps;
    FILE *file2 = fopen(filename, "rb");
    Polynomial *ps2 = readPolynomialsFromFile(file2, &amt_ps);
    assert(amt_ps == 2);
    assert(!memcmp(ps2[0].data, p2.data, sizeof(Monomial) * p2.monomial_amount));
    assert(!memcmp(ps2[1].data, p3.data, sizeof(Monomial) * p3.monomial_amount));
    fclose(file2);
}

void test_positiveFirstNegativeLast() {
    char filename[] = "D:/text_lab_19.txt";
    int all_numbers[] = {1, -3, 7, -4, -12, 3};
    int p_exp[] = {1, 7, 3};
    int n_exp[] = {-3, -4, -12};
    int amt_numbers = 6;

    FILE *file;
    file = fopen(filename, "wb");
    fwrite(&amt_numbers, sizeof(int), 1, file);
    fwrite(all_numbers, sizeof(int), 6, file);
    fclose(file);

    positiveFirstNegativeLast(filename);

    int p_res[3];
    int n_res[3];
    int amt_res;

    file = fopen(filename, "rb");

    fread(&amt_res, sizeof(int), 1, file);
    fread(p_res, sizeof(int), amt_res / 2, file);
    fread(n_res, sizeof(int), amt_res / 2, file);

    fclose(file);

    assert(amt_numbers == amt_res);
    assert(!memcmp(p_exp, p_res, sizeof(int) * 3));
    assert(!memcmp(n_exp, n_res, sizeof(int) * 3));
}

void test_onlySymmetricAndTransposeMatrices() {
    char filename[] = "D:/text_lab_19.txt";
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 4, 7,
                    4, 5, 6,
                    7, 6, 9,
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 7,
                    8, 11,
            },
            2, 2
    );
    matrix m3 = createMatrixFromArray(
            (int[]) {
                    9, 5,
                    5, 8
            },
            2, 2
    );

    matrix ms[] = {m1, m2, m3};

    FILE *file;
    file = fopen(filename, "wb");
    writeMatricesToFile(ms, file, 3);
    fclose(file);

    onlySymmetricAndTransposeMatrices(filename);

    matrix m2_exp = createMatrixFromArray(
            (int[]) {
                    3, 8,
                    7, 11,
            },
            2, 2
    );

    int amt_ms;
    file = fopen(filename, "rb");
    matrix *ms2 = readMatricesFromFile(file, &amt_ms);
    assert(areTwoMatricesEqual(&m1, &ms2[0]));
    assert(areTwoMatricesEqual(&m2_exp, &ms2[1]));
    assert(areTwoMatricesEqual(&m3, &ms2[2]));
    fclose(file);
}

void test_onlyBestSportsmen() {
    char filename[] = "D:/text_lab_19.txt";
    sportsman sp1 = createSportsman("Alex Candley Jefferson", 7);
    sportsman sp2 = createSportsman("Sebastian Henderson Mikhailovich", 10);
    sportsman sp3 = createSportsman("Dexter Day Ivanovich", 5);
    sportsman sp4 = createSportsman("Amelia Murray Alexandrovna", 9);
    sportsman sp5 = createSportsman("Olivia Watson Vladimirovna", 6);
    int amt_sps = 5;

    FILE *file = fopen(filename, "wb");
    fwrite(&amt_sps, sizeof(int), 1, file);
    writeSportsman(sp1, file);
    writeSportsman(sp2, file);
    writeSportsman(sp3, file);
    writeSportsman(sp4, file);
    writeSportsman(sp5, file);
    fclose(file);

    onlyBestSportsmen(filename, 3);

    file = fopen(filename, "rb");
    fread(&amt_sps, sizeof(int), 1, file);
    sportsman *sps = (sportsman *) malloc(amt_sps * sizeof(sportsman));
    for (int i = 0; i < amt_sps; ++i) {
        sps[i] = readSportsmanFromFile(file);
    }
    fclose(file);

    assert(sportsmanCompare(sps, &sp2));
    assert(sportsmanCompare(sps + 1, &sp4));
    assert(sportsmanCompare(sps + 2, &sp1));

}

void test_updateProducts() {
    char filename_have[] = "D:/have.txt";
    char filename_order[] = "D:/order.txt";

    FILE *f_have = fopen(filename_have, "wb");

    products prs_h;
    prs_h.amt_pr = 6;
    prs_h.all_products = malloc(prs_h.amt_pr * sizeof(productDopInfo));

    prs_h.all_products[0] = createProductDopInfo("Onion", 35, 5.0);
    prs_h.all_products[1] = createProductDopInfo("Carrot", 100, 20.0);
    prs_h.all_products[2] = createProductDopInfo("Apple", 240, 16.0);
    prs_h.all_products[3] = createProductDopInfo("Banana", 130, 13.0);
    prs_h.all_products[4] = createProductDopInfo("Cabbage", 12, 35.0);
    prs_h.all_products[5] = createProductDopInfo("Cucumber", 47, 17.0);

    writeProducts(&prs_h, f_have);
    freeProducts(&prs_h);
    fclose(f_have);

    FILE *f_order = fopen(filename_order, "wb");

    int n = 4;
    productInfo *prs_or = malloc(n * sizeof(productInfo));

    prs_or[0] = createProductInfo("Onion", 10);
    prs_or[1] = createProductInfo("Carrot", 15);
    prs_or[2] = createProductInfo("Cabbage", 12);
    prs_or[3] = createProductInfo("Cucumber", 23);

    fwrite(&n, sizeof(int), 1, f_order);
    for (int i = 0; i < n; ++i) {
        writeProductInfo(&prs_or[i], f_order);
        freeProductInfo(&prs_or[i]);
    }
    fclose(f_order);

    FILE *f = fopen(filename_have, "rb");
    products prs = readProducts(f);
    fclose(f);

    FILE *g = fopen(filename_order, "rb");
    updateProducts(&prs, g);
    fclose(g);

    f = fopen(filename_have, "wb");
    writeProducts(&prs, g);
    fclose(f);

    freeProducts(&prs);

    products p_exp;
    p_exp.amt_pr = 5;
    p_exp.all_products = malloc(p_exp.amt_pr * sizeof(productDopInfo));

    p_exp.all_products[0] = createProductDopInfo("Onion", 25, 5.0);
    p_exp.all_products[1] = createProductDopInfo("Carrot", 85, 20.0);
    p_exp.all_products[2] = createProductDopInfo("Apple", 240, 16.0);
    p_exp.all_products[3] = createProductDopInfo("Banana", 130, 13.0);
    p_exp.all_products[4] = createProductDopInfo("Cucumber", 24, 17.0);

    FILE *exp_f = fopen(filename_have, "rb");
    products p_res = readProducts(exp_f);
    fclose(exp_f);

    assert(p_exp.amt_pr == p_res.amt_pr);
    for (int record_index = 0; record_index < p_exp.amt_pr; ++record_index) {
        assert(productDopInfoCmp(p_exp.all_products + record_index,
                                 p_res.all_products + record_index));
    }


    freeProducts(&p_exp);
    freeProducts(&p_res);
}

void test() {
    test_transposeAllMatricesInFile();

    test_solveExample_1Operand();
    test_solveExample_2Operands();
    test_solveExample_3Operands();
    test_solveExample_multiplicationIn2Place();

    test_leftWordsWithSymbols();

    test_onlyLongWords();

    test_onlyPolynomialWithoutRootX();

    test_positiveFirstNegativeLast();

    test_onlySymmetricAndTransposeMatrices();

    test_onlyBestSportsmen();

    test_updateProducts();
}

int main() {
    test();

    return 0;
}