# include "tasks20.h"

// Task 1

matrix changeMatrix(int n, int amt_queries, int *query[]) {
    matrix m = getMemMatrix(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m.values[i][j] = 0;

    for (int i = 0; i < amt_queries; i++)
        for (int row = query[i][0]; row <= query[i][2]; row++)
            for (int col = query[i][1]; col <= query[i][3]; col++)
                m.values[row][col] += 1;

    return m;
}