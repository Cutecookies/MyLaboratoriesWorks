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

// Task 2

matrix lifeGame(matrix board) {
    matrix res_board = getMemMatrix(board.nRows, board.nCols);
    for (int row = 0; row < board.nRows; row++)
        for (int col = 0; col < board.nCols; col++) {
            int amt_life = 0;
            if (col > 0) {
                if (row > 0)
                    amt_life += board.values[row - 1][col - 1];
                if (row < board.nRows - 1)
                    amt_life += board.values[row + 1][col - 1];
                amt_life += board.values[row][col - 1];
            }
            if (col < board.nCols - 1) {
                if (row > 0)
                    amt_life += board.values[row - 1][col + 1];
                if (row < board.nRows - 1)
                    amt_life += board.values[row + 1][col + 1];
                amt_life += board.values[row][col + 1];
            }
            if (row > 0)
                amt_life += board.values[row - 1][col];
            if (row < board.nRows - 1)
                amt_life += board.values[row + 1][col];

            if ((board.values[row][col] == 1 && (amt_life == 2 ||
                                                 amt_life == 3)) ||
                (board.values[row][col] == 0 && amt_life == 3))
                res_board.values[row][col] = 1;
            else
                res_board.values[row][col] = 0;
        }

    return res_board;
}