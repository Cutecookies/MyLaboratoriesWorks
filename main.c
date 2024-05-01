# include "libs/data_structures/flow/flow.h"
# include "libs/data_structures/string_/string_.h"
# include "stdio.h"
# include <stdlib.h>
# include <assert.h>

void test_transposeAllMatricesInFile(){
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
    for(int i = 0; i < 6; i++) {
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

void test() {
    test_transposeAllMatricesInFile();

    test_convertNumbersToFloatingPoint();

    test_solveExample_1Operand();
    test_solveExample_2Operands();
    test_solveExample_3Operands();
    test_solveExample_multiplicationIn2Place();
}

int main() {
    test();

    return 0;
}