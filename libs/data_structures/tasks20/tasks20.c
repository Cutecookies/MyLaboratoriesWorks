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

// Task 3

int cmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void makeArray(matrix m, int row, int col, int *array) {
    array[0] = m.values[row - 1][col - 1];
    array[1] = m.values[row][col - 1];
    array[2] = m.values[row + 1][col - 1];
    array[3] = m.values[row + 1][col];
    array[4] = m.values[row + 1][col + 1];
    array[5] = m.values[row][col + 1];
    array[6] = m.values[row - 1][col + 1];
    array[7] = m.values[row - 1][col];
}

void medianFilter(matrix *m) {
    int amt_array = 8;
    for (int row = 1; row < m->nRows - 1; row++)
        for (int col = 1; col < m->nCols - 1; col++) {
            int array[amt_array];
            makeArray(*m, row, col, array);
            qsort(array, amt_array, sizeof(int), cmp);
            int new_value = (array[3] + array[4]) / 2;
            m->values[row][col] = new_value;
        }
}

// Task 5

int minInt(int a, int b) {
    return a < b ? a : b;
}

int onlyOneMatrices(matrix m) {
    int count = 0;
    matrix m2 = getMemMatrix(m.nRows, m.nCols);
    for (int row = 0; row < m.nRows; row++) {
        m2.values[row][0] = m.values[row][0];

        for (int col = 1; col < m.nCols; col++) {
            if (m.values[row][col])
                m2.values[row][col] =
                        m2.values[row][col - 1] + 1;
            else
                m2.values[row][col] = 0;
        }

        for (int col = 0; col < m.nCols; col++) {
            int min = m2.values[row][col];

            for (int k = row; k >= 0; k--) {
                min = minInt(min, m2.values[k][col]);
                count += min;
            }
        }
    }

    freeMemMatrix(&m2);

    return count;
}

// Task 4

Domain splitDomain(char *s) {
    Domain d;
    char *split = strtok(s, " ");
    d.count = atoi(split);
    split = strtok(NULL, " ");
    d.domain = strdup(split);
    return d;
}

char **getSubdomains(char *domain, int *count) {
    char **sub_domains = malloc((*count + 1) * sizeof(char *));
    char *word = strtok(domain, ".");
    while (word != NULL) {
        sub_domains[*count] = strdup(word);
        (*count)++;
        word = strtok(NULL, ".");
    }
    return sub_domains;
}

void isDomainInArray(Domain *pair_domains, Domain d, int *amt_dm) {
    for (int i = 0; i < *amt_dm; i++) {
        if (strcmp_(d.domain, pair_domains[i].domain) == 0) {
            pair_domains[i].count += d.count;
            return;
        }
    }

    pair_domains[*amt_dm].domain = malloc(270 * sizeof(char));
    strcpy(pair_domains[*amt_dm].domain, d.domain);
    pair_domains[*amt_dm].count = d.count;
    *amt_dm += 1;
}

Domain *getPairDomains(Domain *domains, int size, int *amt) {
    Domain *pair_domains = malloc(size * 3 * sizeof(Domain));
    Domain d;
    for (int i = 0; i < size; i++) {
        int amt_sub_domain = 0;
        char *copy = stringBuffer;
        strcpy(copy, domains[i].domain);
        char **sub_domains = malloc((*amt + 1) * sizeof(char *));
        sub_domains = getSubdomains(copy, &amt_sub_domain);

        for (int j = 0; j < amt_sub_domain; j++) {
            char *pair_domain = malloc(270 * sizeof(char));
            strcpy(pair_domain, "");

            for (int k = j; k < amt_sub_domain; k++) {
                strcat(pair_domain, sub_domains[k]);
                if (k != amt_sub_domain - 1) {
                    strcat(pair_domain, ".");
                }
            }

            d.domain = malloc(270 * sizeof(char));
            strcpy(d.domain, pair_domain);
            d.count = domains[i].count;

            isDomainInArray(pair_domains, d, amt);
            free(pair_domain);
        }
        for (int j = 0; j < amt_sub_domain; j++) {
            free(sub_domains[j]);
        }
        free(sub_domains);
    }
    return pair_domains;
}

void freeMemory(Domain *domains, int amt_domains) {
    for (int i = 0; i < amt_domains; i++) {
        free(domains[i].domain);
    }
    free(domains);
}

Domain *getAllDomains(char *cpdomains[], int amt_domains, int *amt) {
    Domain *domains = malloc(amt_domains * 3 * sizeof(Domain));
    for (int i = 0; i < amt_domains; i++) {
        domains[i] = splitDomain(cpdomains[i]);
    }


    Domain *pair_domains = getPairDomains(domains, amt_domains, amt);

    freeMemory(domains, amt_domains);
    return pair_domains;
}