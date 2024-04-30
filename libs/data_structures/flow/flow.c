# include "flow.h"
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

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

// Task 2

void createFileWithFloatNumbers(char *filename) {
    FILE *file = fopen(filename, "w");
    int amt_n = 6;
    float n[] = {123.456, 4832.43523, 1.4324, 423, 0.34, 0.00023};
    for(int i = 0; i < amt_n; i++) {
        fprintf(file, "%f\n", n[i]);
    }
    fclose(file);
}

vectorVoid readFloatNumbersFromFile(char *filename) {
    FILE *file = fopen(filename, "r");
    vectorVoid numbers = createVectorV(0, sizeof(float));
    float x;
    while(fscanf(file, "%f", &x) != EOF) {
        pushBackV(&numbers, &x);
    }
    fclose(file);
    return numbers;
}

void writeFloatNumbersToFile(char *filename, float *numbers, int amt_n) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < amt_n; i++) {
        fprintf(file, "%0.2e\n", numbers[i]);
    }
    fclose(file);
}

void convertNumbersToFloatingPoint(char *filename) {
    vectorVoid numbers = readFloatNumbersFromFile(filename);
    float* n = numbers.data;
    int amt_n = numbers.size;
    writeFloatNumbersToFile(filename, n, amt_n);
}