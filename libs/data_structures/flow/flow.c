# include "flow.h"
# include <ctype.h>
# include "stdio.h"
# include "string.h"
# include "stdlib.h"
#include <stdio.h>

// Task 1

void createFileWithMatrices(char *filename) {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9,
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    3, 8,
                    11, 16,
            },
            2, 2
    );
    matrix m3 = createMatrixFromArray(
            (int[]) {
                    3,
            },
            1, 1
    );

    matrix matrices[] = {m1, m2, m3};
    writeMatrices(matrices, filename, 3);
    freeMemMatrices(matrices, 3);
}

void transposeAllMatricesInFile(char *filename) {
    int amt_m;

    matrix *matrices = readMatrices(filename, &amt_m);
    for (int i = 0; i < amt_m; i++) {
        transposeMatrix(&matrices[i]);
    }
    writeMatrices(matrices, filename, amt_m);
}