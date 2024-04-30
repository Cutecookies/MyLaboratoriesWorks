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

void test() {
    test_transposeAllMatricesInFile();
}

int main() {
    test();

    return 0;
}