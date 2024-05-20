# include "libs/data_structures/tasks20/tasks20.h"
# include "libs/data_structures/matrix/matrix.h"
# include "stdio.h"
# include <stdlib.h>
# include <assert.h>

// Task 1

void test_changeMatrix1() {
    int n = 3;
    int amt_queries = 2;
    matrix query = createMatrixFromArray(
            (int[]) {
                    1, 1, 2, 2,
                    0, 0, 1, 1,
            },
            2, 4
    );
    matrix exp = createMatrixFromArray(
            (int[]) {
                    1, 1, 0,
                    1, 2, 1,
                    0, 1, 1,
            },
            3, 3
    );

    matrix res = changeMatrix(n, amt_queries, query.values);
    assert(areTwoMatricesEqual(&exp, &res));
    freeMemMatrix(&query);
    freeMemMatrix(&exp);
}

void test_changeMatrix2() {
    int n = 4;
    int amt_queries = 3;
    matrix query = createMatrixFromArray(
            (int[]) {
                    1, 1, 2, 2,
                    0, 0, 1, 2,
                    2, 2, 3, 3,

            },
            3, 4
    );
    matrix exp = createMatrixFromArray(
            (int[]) {
                    1, 1, 1, 0,
                    1, 2, 2, 0,
                    0, 1, 2, 1,
                    0, 0, 1, 1,
            },
            4, 4
    );

    matrix res = changeMatrix(n, amt_queries, query.values);
    assert(areTwoMatricesEqual(&exp, &res));
    freeMemMatrix(&query);
    freeMemMatrix(&exp);
}

// Task 2

void test_lifeGame1() {
    matrix board = createMatrixFromArray(
            (int[]) {
                    0, 1, 0,
                    0, 0, 1,
                    1, 1, 1,
                    0, 0, 0,
            },
            4, 3
    );
    matrix exp_board = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    1, 0, 1,
                    0, 1, 1,
                    0, 1, 0,
            },
            4, 3
    );

    matrix res_board = lifeGame(board);
    assert(areTwoMatricesEqual(&exp_board, &res_board));
    freeMemMatrix(&board);
    freeMemMatrix(&exp_board);
}

void test_lifeGame2() {
    matrix board = createMatrixFromArray(
            (int[]) {
                    1, 0, 1,
                    0, 0, 1,
                    1, 1, 0,
            },
            3, 3
    );
    matrix exp_board = createMatrixFromArray(
            (int[]) {
                    0, 1, 0,
                    1, 0, 1,
                    0, 1, 0,
            },
            3, 3
    );

    matrix res_board = lifeGame(board);
    assert(areTwoMatricesEqual(&exp_board, &res_board));
    freeMemMatrix(&board);
    freeMemMatrix(&exp_board);
}

// Task 3

void test_medianFilter1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 20, 30,
                    25, 35, 45,
                    15, 25, 35,
            },
            3, 3
    );
    matrix exp = createMatrixFromArray(
            (int[]) {
                    10, 20, 30,
                    25, 25, 45,
                    15, 25, 35,
            },
            3, 3
    );

    medianFilter(&m);
    assert(areTwoMatricesEqual(&m, &exp));
    freeMemMatrix(&m);
    freeMemMatrix(&exp);
}

void test_medianFilter2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 4, 7, 3, 2,
                    4, 3, 8, 6, 1,
                    2, 5, 3, 6, 2,
                    6, 4, 2, 6, 1,
                    6, 9, 7, 1, 4,
            },
            5, 5
    );
    matrix exp = createMatrixFromArray(
            (int[]) {
                    1, 4, 7, 3, 2,
                    4, 4, 4, 3, 1,
                    2, 4, 4, 2, 2,
                    6, 5, 4, 3, 1,
                    6, 9, 7, 1, 4,
            },
            5, 5
    );

    medianFilter(&m);
    assert(areTwoMatricesEqual(&m, &exp));
    freeMemMatrix(&m);
    freeMemMatrix(&exp);
}

void test_medianFilter3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 4, 7, 3, 2, 7, 3,
                    4, 3, 8, 6, 1, 11, 13,
                    2, 5, 3, 9, 14, 6, 2,
                    6, 11, 4, 2, 6, 5, 1,
                    6, 9, 7, 9, 10, 18, 4,
                    7, 12, 13, 4, 15, 3, 6,
                    9, 10, 6, 0, 4, 3, 7,
            },
            7, 7
    );
    matrix exp = createMatrixFromArray(
            (int[]) {
                    1, 4, 7, 3, 2, 7, 3,
                    4, 4, 4, 3, 6, 6, 13,
                    2, 4, 4, 4, 5, 5, 2,
                    6, 5, 4, 5, 5, 5, 1,
                    6, 6, 5, 5, 5, 5, 4,
                    7, 6, 5, 5, 4, 4, 6,
                    9, 10, 6, 0, 4, 3, 7,
            },
            7, 7
    );

    medianFilter(&m);
    assert(areTwoMatricesEqual(&m, &exp));
    freeMemMatrix(&m);
    freeMemMatrix(&exp);
}

// Task 4

void test_getAllDomains1() {
    char s1[] = "9001 discuss.codeforces.com";
    char *cpdomains[] = {s1};

    int amt = 0;

    Domain *res = getAllDomains(cpdomains, 1, &amt);

    for (int i = 0; i < amt; i++) {
        printf("%d ", res[i].count);
        printf("%s\n", res[i].domain);
    }
}

void test_getAllDomains2() {
    char s1[] = "900 google.mail.com";
    char s2[] = "50 yahoo.com";
    char s3[] = "1 intel.mail.com";
    char s4[] = "5 wiki.org";
    char *cpdomains[] = {s1, s2, s3, s4};

    int amt = 0;

    Domain *res = getAllDomains(cpdomains, 4, &amt);

    for (int i = 0; i < amt; i++) {
        printf("%d ", res[i].count);
        printf("%s\n", res[i].domain);
    }
}

// Task 5

void test_onlyOneMatrices1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    1, 1, 1,
                    0, 1, 0,
            }, 3, 3
    );


    assert(onlyOneMatrices(m) == 10);

    freeMemMatrix(&m);
}

void test_onlyOneMatrices2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0, 1,
                    1, 1, 1, 1,
                    1, 1, 0, 1,
                    0, 1, 1, 0,
            }, 4, 4
    );


    assert(onlyOneMatrices(m) == 29);

    freeMemMatrix(&m);
}

void test_returnNumberFromTwoLetters1() {
    char *s = "DDD";
    returnNumberFromTwoLetters(s);
}

void test_returnNumberFromTwoLetters2() {
    char *s = "IIIDIDDD";
    returnNumberFromTwoLetters(s);
}

void test_returnChangedStr1() {
    char *s = "abc";
    int amt = 3;
    int numbers[3] = {0, 1, 2};

    char *res = returnChangedStr(s, numbers, amt);
    char *exp = "abc";

    assert(strcmp_(res, exp) == 0);
}

void test_returnChangedStr2() {
    char *s = "abap";
    int amt = 4;
    int numbers[4] = {0, 3, 2, 1};

    char *res = returnChangedStr(s, numbers, amt);
    char *exp = "apab";

    assert(strcmp_(res, exp) == 0);
}

void test() {
    test_changeMatrix1();
    test_changeMatrix2();

    test_lifeGame1();
    test_lifeGame2();

    test_medianFilter1();
    test_medianFilter2();
    test_medianFilter3();

//    test_getAllDomains1();
//    test_getAllDomains2();

    test_onlyOneMatrices1();
    test_onlyOneMatrices2();

//    test_returnNumberFromTwoLetters1();
//    test_returnNumberFromTwoLetters2();

    test_returnChangedStr1();
    test_returnChangedStr2();
}

// Task 9

void test_writeNumbersLessN(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error");
        return;
    }

    char *filename_r = argv[1];
    char *filename_w = argv[2];
    int n = atoi(argv[3]);

    writeNumbersLessN(filename_w, filename_r, n);

    FILE *f = fopen(filename_w, "r");
    int res[5];
    int i = 0;
    int num;
    while (fscanf(f, "%d", &num) == 1) {
        res[i] = num;
        i++;
    }

    fclose(f);

    int exp[5] = {2, 4, 3, 4, 4};
    for (int j = 0; j < 5; j++) {
        assert(exp[j] == res[j]);
    }
}

// Task 10

void test_printNStr(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Error");
        return;
    }

    char *filename = argv[1];
    int n = atoi(argv[2]);

    printNStr(filename, n);
}

// Task 7

void test_buildTree1() {
    int nums[] = {3, 2, 1, 6, 0, 5};
    int size = 6;
    buildTree(nums, size);
    printf("\n");
}

void test_buildTree2() {
    int nums[] = {3, 2, 1};
    int size = 3;
    buildTree(nums, size);
}

void test_printNumbers() {
    int n = 10;
    int q = 3;
    char dictonary[10][MAX_STR_SIZE] = {"aa",
                                        "aaa",
                                        "aab",
                                        "ab",
                                        "abc",
                                        "ac",
                                        "ba",
                                        "daa",
                                        "dab",
                                        "dadba"};

    Query queries[3] = {{4, "a"}, {2, "da"}, {4, "da"}};

    printNumbers(dictonary, n, queries, q);
}

int main() {
    test_printNumbers();

    return 0;
}