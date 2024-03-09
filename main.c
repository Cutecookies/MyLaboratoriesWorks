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

void test() {
    test_inputMatrix_notEmptyMatrix();
    test_inputMatrices_notEmptyMatrix();
}

int main() {
    test();

    return 0;
}