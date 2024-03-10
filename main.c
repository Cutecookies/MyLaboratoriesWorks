# include <assert.h>
# include "libs/data_structures/vector/vector.h"
# include "libs/data_structures/matrix/matrix.h"
# include "stdio.h"
# include "stdbool.h"

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

void test_isSquareMatrix_squareMatrix(){
    matrix mtx = getMemMatrix(2, 2);

    assert(isSquareMatrix(&mtx));
}

void test_isSquareMatrix_notSquareMatrix(){
    matrix mtx = getMemMatrix(3, 2);

    assert(!isSquareMatrix(&mtx));
}

void test_areTwoMatricesEqual_twoMatricesEqual() {
    matrix mtx1 = getMemMatrix(2, 2);
    mtx1.values[0][0] = 2;
    mtx1.values[0][1] = 3;
    mtx1.values[1][0] = 2;
    mtx1.values[1][1] = 3;

    matrix mtx2 = getMemMatrix(2, 2);
    mtx2.values[0][0] = 2;
    mtx2.values[0][1] = 3;
    mtx2.values[1][0] = 2;
    mtx2.values[1][1] = 3;

    assert(areTwoMatricesEqual(&mtx1, &mtx2));
}

void test_areTwoMatricesEqual_twoMatricesNotEqualValues() {
    matrix mtx1 = getMemMatrix(2, 2);
    mtx1.values[0][0] = 2;
    mtx1.values[0][1] = 2;
    mtx1.values[1][0] = 2;
    mtx1.values[1][1] = 3;

    matrix mtx2 = getMemMatrix(2, 2);
    mtx2.values[0][0] = 2;
    mtx2.values[0][1] = 3;
    mtx2.values[1][0] = 2;
    mtx2.values[1][1] = 3;

    assert(!areTwoMatricesEqual(&mtx1, &mtx2));
}

void test_areTwoMatricesEqual_twoMatricesNotEqualSize() {
    matrix mtx1 = getMemMatrix(2, 2);
    mtx1.values[0][0] = 2;
    mtx1.values[0][1] = 2;
    mtx1.values[1][0] = 2;
    mtx1.values[1][1] = 3;

    matrix mtx2 = getMemMatrix(2, 1);
    mtx2.values[0][0] = 2;
    mtx2.values[1][0] = 2;

    assert(!areTwoMatricesEqual(&mtx1, &mtx2));
}

void test_isEMatrix_eMatrix() {
    matrix mtx = getMemMatrix(3, 3);
    mtx.values[0][0] = 1;
    mtx.values[0][1] = 0;
    mtx.values[0][2] = 0;
    mtx.values[1][0] = 0;
    mtx.values[1][1] = 1;
    mtx.values[1][2] = 0;
    mtx.values[2][0] = 0;
    mtx.values[2][1] = 0;
    mtx.values[2][2] = 1;

    assert(isEMatrix(&mtx));
}

void test_isEMatrix_notEMatrix() {
    matrix mtx = getMemMatrix(3, 3);
    mtx.values[0][0] = 1;
    mtx.values[0][1] = 1;
    mtx.values[0][2] = 1;
    mtx.values[1][0] = 0;
    mtx.values[1][1] = 0;
    mtx.values[1][2] = 0;
    mtx.values[2][0] = 0;
    mtx.values[2][1] = 0;
    mtx.values[2][2] = 1;

    assert(!isEMatrix(&mtx));
}

void test_isSymmetricMatrix_symmetricMatrix() {
    matrix mtx = getMemMatrix(3, 3);
    mtx.values[0][0] = 1;
    mtx.values[0][1] = 4;
    mtx.values[0][2] = 5;
    mtx.values[1][0] = 4;
    mtx.values[1][1] = 2;
    mtx.values[1][2] = 6;
    mtx.values[2][0] = 5;
    mtx.values[2][1] = 6;
    mtx.values[2][2] = 3;

    assert(isSymmetricMatrix(&mtx));
}

void test_isSymmetricMatrix_notSymmetricMatrix() {
    matrix mtx = getMemMatrix(3, 3);
    mtx.values[0][0] = 1;
    mtx.values[0][1] = 4;
    mtx.values[0][2] = 4;
    mtx.values[1][0] = 4;
    mtx.values[1][1] = 2;
    mtx.values[1][2] = 3;
    mtx.values[2][0] = 5;
    mtx.values[2][1] = 1;
    mtx.values[2][2] = 3;

    assert(!isSymmetricMatrix(&mtx));
}

void test_transposeSquareMatrix() {
    matrix mtx = getMemMatrix(3, 3);
    mtx.values[0][0] = 1;
    mtx.values[0][1] = 2;
    mtx.values[0][2] = 3;
    mtx.values[1][0] = 4;
    mtx.values[1][1] = 5;
    mtx.values[1][2] = 6;
    mtx.values[2][0] = 7;
    mtx.values[2][1] = 8;
    mtx.values[2][2] = 9;

    transposeSquareMatrix(&mtx);

    assert(mtx.values[0][1] == 4);
    assert(mtx.values[0][2] == 7);
    assert(mtx.values[1][0] == 2);
    assert(mtx.values[1][2] == 8);
    assert(mtx.values[2][0] == 3);
    assert(mtx.values[2][1] == 6);
}

void test_transposeMatrix() {
    matrix mtx = getMemMatrix(3, 2);
    mtx.values[0][0] = 1;
    mtx.values[0][1] = 2;
    mtx.values[1][0] = 3;
    mtx.values[1][1] = 4;
    mtx.values[2][0] = 5;
    mtx.values[2][1] = 6;

    transposeMatrix(&mtx);

    assert(mtx.values[0][0] == 1);
    assert(mtx.values[0][1] == 3);
    assert(mtx.values[0][2] == 5);
    assert(mtx.values[1][0] == 2);
    assert(mtx.values[1][1] == 4);
    assert(mtx.values[1][2] == 6);
    assert(mtx.nRows == 2);
    assert(mtx.nCols == 3);
}

void test_getMinValuePos() {
    matrix mtx = getMemMatrix(2, 3);
    mtx.values[0][0] = 20;
    mtx.values[0][1] = 23;
    mtx.values[0][2] = 17;
    mtx.values[1][0] = 22;
    mtx.values[1][1] = 13;
    mtx.values[1][2] = 12;

    position pos = getMinValuePos(mtx);

    assert(pos.rowIndex == 1);
    assert(pos.colIndex == 2);
}

void test_getMaxValuePos() {
    matrix mtx = getMemMatrix(2, 3);
    mtx.values[0][0] = 20;
    mtx.values[0][1] = 23;
    mtx.values[0][2] = 17;
    mtx.values[1][0] = 22;
    mtx.values[1][1] = 13;
    mtx.values[1][2] = 12;

    position pos = getMaxValuePos(mtx);

    assert(pos.rowIndex == 0);
    assert(pos.colIndex == 1);
}

void test() {
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria_unsortedMatrix();
    test_selectionSortColsMatrixByColCriteria_unsortedMatrix();
    test_isSquareMatrix_squareMatrix();
    test_isSquareMatrix_notSquareMatrix();
    test_areTwoMatricesEqual_twoMatricesEqual();
    test_areTwoMatricesEqual_twoMatricesNotEqualValues();
    test_areTwoMatricesEqual_twoMatricesNotEqualSize();
    test_isEMatrix_eMatrix();
    test_isEMatrix_notEMatrix();
    test_isSymmetricMatrix_symmetricMatrix();
    test_isSymmetricMatrix_notSymmetricMatrix();
    test_transposeSquareMatrix();
    test_transposeMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

int main() {
    test();

    return 0;
}