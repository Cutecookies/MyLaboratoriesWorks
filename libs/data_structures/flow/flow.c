# include "flow.h"
# include <ctype.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

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
    for (int i = 0; i < amt_n; i++) {
        fprintf(file, "%f\n", n[i]);
    }
    fclose(file);
}

vectorVoid readFloatNumbersFromFile(char *filename) {
    FILE *file = fopen(filename, "r");
    vectorVoid numbers = createVectorV(0, sizeof(float));
    float x;
    while (fscanf(file, "%f", &x) != EOF) {
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
    float *n = numbers.data;
    int amt_n = numbers.size;
    writeFloatNumbersToFile(filename, n, amt_n);
}

// Task 3

float makeOperation(float n1, float n2, char op) {
    if (op == '-')
        return n1 - n2;
    if (op == '+')
        return n1 + n2;
    if (op == '*')
        return n1 * n2;
    return n1 / n2;
}

void writeOperation(char *filename, float *operands, char *operations,
                    int amt_op) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "%f", operands[0]);
    for (int i = 0; i < amt_op; i++) {
        fprintf(file, " %c", operations[i]);
        fprintf(file, " %f", operands[i + 1]);
    }
    fclose(file);
}

void writeOperationAndAnswer(char *filename, float *operands, char *operations,
                             int amt_op, float answer) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "%f", operands[0]);
    for (int i = 0; i < amt_op; i++) {
        fprintf(file, " %c", operations[i]);
        fprintf(file, " %f", operands[i + 1]);
    }
    fprintf(file, "\n%f", answer);
    fclose(file);
}

void solveExample(char *filename) {
    float answer;

    FILE *file = fopen(filename, "r");
    float operands[3];
    char operations[2];
    int amt_op = 0;
    fscanf(file, "%f", &operands[0]);
    for (int i = 0; i < 2; i++) {
        if (fscanf(file, " %c", &operations[i]) != EOF) {
            fscanf(file, " %f", &operands[i + 1]);
            amt_op++;
        }
    }

    fclose(file);
    if (amt_op == 0) {
        answer = operands[0];
    } else if (amt_op == 1)
        answer = makeOperation(operands[0], operands[1], operations[0]);
    else {
        float firs_act;
        if (operations[0] == '*' || operations[0] == '/' ||
            (operations[1] != '*' && operations[1] != '/')) {
            firs_act = makeOperation(operands[0], operands[1], operations[0]);
            answer = makeOperation(firs_act, operands[2], operations[1]);
        } else {
            firs_act = makeOperation(operands[1], operands[2], operations[1]);
            answer = makeOperation(operands[0], firs_act, operations[0]);
        }
    }
    writeOperationAndAnswer(filename, operands, operations, amt_op, answer);
}

// Task 4

int compareStr(const char *w1, const char *w2, long n) {
    for (int i = 0; i < n; i++) {
        if (*w1 != *w2)
            return 0;
        w1++;
        w2++;
    }
    return 1;
}

long getFileSize(const char *filename) {
    long file_size = 0;
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
        file_size = -1;

    else {
        while (getc(file) != EOF)
            file_size++;
        fclose(file);
    }
    return file_size;
}

void writeWordsInFile(char *filename, char words[100][100], int amt_w) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "%s", words[0]);
    for (int i = 1; i < amt_w; i++) {
        fprintf(file, " %s", words[i]);
    }
    fclose(file);
}

void writeBufferInFile(char *filename, char *buf) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "%s\n", buf);
    fclose(file);
}

void leftWordsWithSymbols(char *filename, const char *symbols) {
    long filesize = getFileSize(filename) + 1;
    char *buffer = malloc(filesize);

    FILE *file = fopen(filename, "r");

    char *word = buffer;
    while (fscanf(file, "%s", word) != EOF)
        if (strstr(word, symbols)) {
            word += strlen(word);
            *word = ' ';
            word++;
        }
    *word = '\0';
    fclose(file);

    writeBufferInFile(filename, buffer);
    free(buffer);
}

// Task 5