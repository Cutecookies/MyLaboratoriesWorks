# include "matrix.h"
# include "malloc.h"
# include <stdio.h>
# include "assert.h"


matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int*) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);
    return (matrix){values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices,
                              int nRows, int nCols) {
    matrix *ms = (matrix*) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);
    return ms;
}

void freeMemMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        free(m->values[i]);
    }
    free(m->values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        freeMemMatrix(&ms[i]);
    }
}

void inputMatrix(matrix *m) {
    for (int i = 0; i < m->nRows; i++) {
        inputArray_(m->values[i], m->nCols);
    }
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        inputMatrix(&ms[i]);
    }
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        outputArray_(m.values[i], m.nCols);
    }
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++) {
        outputMatrix(ms[i]);
        if (i < nMatrices - 1)
            printf("\n");
    }
}

void swapRows(matrix m, int i1, int i2) {
    assert(i1 <= m.nRows && i2 <= m.nRows);

    int *temp = m.values[i1 - 1];
    m.values[i1 - 1] = m.values[i2 - 1];
    m.values[i2 - 1] = temp;
}

void swapColumns(matrix m, int j1, int j2) {
    assert(j1 <= m.nCols && j2 <= m.nCols);

    for (int i = 0; i < m.nRows; i++) {
        int temp = m.values[i][j1 - 1];
        m.values[i][j1 - 1] = m.values[i][j2 - 1];
        m.values[i][j2 - 1] = temp;
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m,
                                          int (*criteria)(int*, int)) {
    int criteria_res[m.nRows] = {};
    for (int i = 0; i < m.nRows; i++) {
        int temp = criteria(m.values[i], m.nCols);
        criteria_res[i] = temp;
    }

    for (int i = 1; i < m.nRows; i++) {
        int temp = criteria_res[i];
        int *t = m.values[i];
        int j = i;
        while (j > 0 && criteria_res[j - 1] > temp) {
            criteria_res[j] = criteria_res[j - 1];
            swapRows(m, j + 1, j);
            j--;
        }
        criteria_res[j] = temp;
        m.values[j] = t;
    }
}

void selectionSortColsMatrixByColCriteria(matrix m,
                                          int (*criteria)(int*, int)) {
    int criteria_res[m.nCols] = {};
    for (int i = 0; i < m.nCols; i++) {
        int column[m.nRows] = {};
        for (int j = 0; j < m.nRows; j++) {
            int temp = m.values[j][i];
            column[j] = temp;
        }

        int temp = criteria(column, m.nRows);
        criteria_res[i] = temp;
    }

    for (int i = 0; i < m.nCols - 1; i++) {
        int min_pos = i;
        for (int j = i + 1; j < m.nCols; j++){
            if (criteria_res[j] < criteria_res[min_pos])
                min_pos = j;
        }
        int temp = criteria_res[i];
        criteria_res[i] = criteria_res[min_pos];
        criteria_res[min_pos] = temp;

        swapColumns(m, i + 1, min_pos + 1);
    }
}