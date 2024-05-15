#ifndef LABORATORIESWORKS_TASKS20_H
#define LABORATORIESWORKS_TASKS20_H

# include "../matrix/matrix.h"
# include "../../algorithms/array/array.h"
#include <stdlib.h>

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

#endif //LABORATORIESWORKS_TASKS20_H
