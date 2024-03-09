# include <assert.h>
# include "libs/data_structures/vector/vector.h"
# include "libs/data_structures/matrix/matrix.h"
# include "stdio.h"

void test_inputMatrix_notEmptyMatrix() {
    matrix mtx = getMemMatrix(2, 3);
    inputMatrix(&mtx);
    outputMatrix(mtx);
}

void test_inputMatrices_notEmptyMatrix() {
    matrix *mtx = getMemArrayOfMatrices(2, 2, 3);
    inputMatrices(mtx, 2);
    outputMatrices(mtx, 2);
}

void test_swapRows() {
    matrix mtx = getMemMatrix(2, 2);
    mtx.values[0][0] = 1;
    mtx.values[0][1] = 2;
    mtx.values[1][0] = 3;
    mtx.values[1][1] = 4;

    swapRows(mtx, 1, 2);

    assert(mtx.values[0][0] == 3);
    assert(mtx.values[0][1] == 4);
    assert(mtx.values[1][0] == 1);
    assert(mtx.values[1][1] == 2);
}

void test_swapColumns() {
    matrix mtx = getMemMatrix(2, 2);
    mtx.values[0][0] = 1;
    mtx.values[0][1] = 2;
    mtx.values[1][0] = 3;
    mtx.values[1][1] = 4;

    swapColumns(mtx, 1, 2);

    assert(mtx.values[0][0] == 2);
    assert(mtx.values[0][1] == 1);
    assert(mtx.values[1][0] == 4);
    assert(mtx.values[1][1] == 3);
}

void test() {
    test_swapRows();
    test_swapColumns();
}

int main() {
    test();

    return 0;
}