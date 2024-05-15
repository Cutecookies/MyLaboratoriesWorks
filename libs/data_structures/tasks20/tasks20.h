#ifndef LABORATORIESWORKS_TASKS20_H
#define LABORATORIESWORKS_TASKS20_H

# include "../matrix/matrix.h"
# include "../../algorithms/array/array.h"

// Task 1

// изменение матрицы, добавлением 1 к каждому элементу подматрицы
// верхний левый угол и нижний правый угол.
matrix changeMatrix(int n, int amt_queries, int *query[]);

// Task 2

// возвращает следующее состояние доски
matrix lifeGame(matrix board);

#endif //LABORATORIESWORKS_TASKS20_H
