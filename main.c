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

void test() {
    test_changeMatrix1();
    test_changeMatrix2();

    test_lifeGame1();
    test_lifeGame2();
}

int main() {
    test();

    return 0;
}