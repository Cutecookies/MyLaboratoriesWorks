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
        while (fgetc(file) != EOF)
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

int wordLen(WordDescriptor word) {
    return word.end - word.begin;
}

WordDescriptor wordMaxLen(char *words) {
    getBagOfWords(&_bag, words);
    WordDescriptor max_len_word;
    int max_len;
    max_len_word = _bag.words[0];
    max_len = wordLen(max_len_word);
    int cur_len;
    for (int i = 1; i < _bag.size; i++) {
        cur_len = wordLen(_bag.words[i]);
        if (cur_len > max_len) {
            max_len = cur_len;
            max_len_word = _bag.words[i];
        }
    }
    return max_len_word;
}

void writeWords(char *filename, char *words[], int n) {
    FILE *file = fopen(filename, "w");
    for (int i = 0; i < n; i++) {
        fprintf(file, "%s\n", words[i]);
        free(words[i]);
    }
    fclose(file);
}

void onlyLongWords(char *filename) {
    long int file_size = getFileSize(filename);
    char *buffer = malloc(file_size);
    FILE *file = fopen(filename, "r");
    WordDescriptor word;

    char *words[1000];
    int ind = 0;

    while (fgets(buffer, file_size, file) != NULL) {
        word = wordMaxLen(buffer);
        words[ind] = malloc(wordLen(word) + 1);
        wordDescriptorToString(word, words[ind++]);
    }
    fclose(file);

    writeWords(filename, words, ind);
}

// Task 6

Polynomial createPolynomialFromArray(const int degrees[],
                                     const double coefficients[],
                                     int amt_args) {
    Polynomial p;
    p.monomial_amount = amt_args;
    p.data = (Monomial *) malloc(amt_args * sizeof(Monomial));

    for (int i = 0; i < amt_args; ++i) {
        p.data[i].coefficient = coefficients[i];
        p.data[i].degree = degrees[i];
    }

    return p;
}

Polynomial readPolynomialFromFile(FILE *file) {
    Polynomial p;
    fread(&p.monomial_amount, sizeof(int), 1, file);

    p.data = (Monomial *) malloc(p.monomial_amount * sizeof(Monomial));

    fread(p.data, sizeof(Monomial), p.monomial_amount, file);

    return p;
}

Polynomial *readPolynomialsFromFile(FILE *file, int *pol_amount) {
    fread(pol_amount, sizeof(int), 1, file);

    Polynomial *buffer = malloc(*pol_amount * sizeof(Polynomial));
    for (int pol_index = 0; pol_index < *pol_amount; ++pol_index) {
        buffer[pol_index] = readPolynomialFromFile(file);
    }

    return buffer;
}

void writePolynomialToFile(Polynomial p, FILE *file) {
    fwrite(&p.monomial_amount, sizeof(int), 1, file);
    fwrite(p.data, sizeof(Monomial), p.monomial_amount, file);
}

void writePolynomialsToFile(Polynomial *ps, FILE *file, int pol_amount) {
    fwrite(&pol_amount, sizeof(int), 1, file);

    for (int pol_i = 0; pol_i < pol_amount; ++pol_i) {
        writePolynomialToFile(ps[pol_i], file);
    }
}

double calculatePolynomial(Polynomial p, double x) {
    double result = 0;
    double x_n = 1;
    int ind = p.monomial_amount - 1;

    for (int degree = 0; degree <= p.data[0].degree; degree++) {
        if (p.data[ind].degree == degree) {
            result += p.data[ind].coefficient * x_n;
            ind--;
        }
        x_n *= x;
    }

    return result;
}

void freePolynomial(Polynomial *p) {
    free(p->data);
    p->data = NULL;
    p->monomial_amount = 0;
}

void freePolynomials(Polynomial *ps, int pol_amount) {
    for (int pol_index = 0; pol_index < pol_amount; ++pol_index) {
        freePolynomial(ps + pol_index);
    }
}

void onlyPolynomialWithoutRootX(char *filename, int x) {
    FILE *file;
    file = fopen(filename, "rb+");
    int amt_ps;
    Polynomial *ps = readPolynomialsFromFile(file, &amt_ps);
    fclose(file);

    Polynomial ps2[amt_ps];
    int cur_size = 0;
    for (int i = 0; i < amt_ps; i++) {
        if(fabs(calculatePolynomial(ps[i], x)) > 0.00001)
            ps2[cur_size++] = ps[i];
    }

    file = fopen(filename, "wb+");
    fwrite(&cur_size, sizeof(int), 1, file);
    for (int i = 0; i < cur_size; i++)
        writePolynomialToFile(ps2[i], file);
    fclose(file);

    freePolynomials(ps, amt_ps);
    freePolynomials(ps2, cur_size);
    free(ps);
}