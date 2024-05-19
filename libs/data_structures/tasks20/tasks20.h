#ifndef LABORATORIESWORKS_TASKS20_H
#define LABORATORIESWORKS_TASKS20_H

# include "../matrix/matrix.h"
# include "../../algorithms/array/array.h"
# include "../string_/string_.h"
#include <stdlib.h>
# include <ctype.h>


// Task 1

// изменение матрицы, добавлением 1 к каждому элементу подматрицы
// верхний левый угол и нижний правый угол.
matrix changeMatrix(int n, int amt_queries, int *query[]);

// Task 2

// возвращает следующее состояние доски
matrix lifeGame(matrix board);

// Task 3

// сравнение
int cmp(const void *a, const void *b);

// создание массива из чисел в матрице вокруг числа
void makeArray(matrix m, int row, int col, int *array);

// замена числа медианой отсортированного массива
void medianFilter(matrix *m);

// Task 5

int minInt(int a, int b);

int onlyOneMatrices(matrix m);

// Task 4

typedef struct {
    int count;
    char *domain;
} Domain;

// Функция для разделения строки на домен и счетчик
Domain splitDomain(char *s);

// Функция для получения всех поддоменов из домена
char **getSubdomains(char *domain, int *count);

void isDomainInArray(Domain *pair_domains, Domain d, int *amt_dm);

// Функция для формирования доменов с парным счетчиком
Domain *getPairDomains(Domain *domains, int size, int *amt);

// Функция для освобождения памяти
void freeMemory(Domain *domains, int amt_domains);

Domain *getAllDomains(char *cpdomains[], int amt_domains, int *amt);

#endif //LABORATORIESWORKS_TASKS20_H
