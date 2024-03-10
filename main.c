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

int getSum(int *a, int n) {
    int s = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];
    };
    return s;
}

void test_insertionSortRowsMatrixByRowCriteria_unsortedMatrix() {
    matrix mtx = getMemMatrix(3, 2);
    mtx.values[0][0] = 2;
    mtx.values[0][1] = 2;
    mtx.values[1][0] = 3;
    mtx.values[1][1] = 3;
    mtx.values[2][0] = 1;
    mtx.values[2][1] = 1;

    insertionSortRowsMatrixByRowCriteria(mtx, getSum);

    assert(mtx.values[0][0] == 1);
    assert(mtx.values[0][1] == 1);
    assert(mtx.values[1][0] == 2);
    assert(mtx.values[1][1] == 2);
    assert(mtx.values[2][0] == 3);
    assert(mtx.values[2][1] == 3);
}

void test_selectionSortColsMatrixByColCriteria_unsortedMatrix() {
    matrix mtx = getMemMatrix(2, 3);
    mtx.values[0][0] = 2;
    mtx.values[0][1] = 3;
    mtx.values[0][2] = 1;
    mtx.values[1][0] = 2;
    mtx.values[1][1] = 3;
    mtx.values[1][2] = 1;

    selectionSortColsMatrixByColCriteria(mtx, getSum);

    assert(mtx.values[0][0] == 1);
    assert(mtx.values[0][1] == 2);
    assert(mtx.values[0][2] == 3);
    assert(mtx.values[1][0] == 1);
    assert(mtx.values[1][1] == 2);
    assert(mtx.values[1][2] == 3);
}

void test() {
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria_unsortedMatrix();
    test_selectionSortColsMatrixByColCriteria_unsortedMatrix();
}

int main() {
    test();

    return 0;
}