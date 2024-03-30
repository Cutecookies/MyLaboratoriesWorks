# include <assert.h>
# include "libs/data_structures/matrix/matrix.h"

// меняет местами строки, в которых находятся
// максимальный и минимальный элементы.
void swapRowsMinMaxElement(matrix m) {
    int row_min_el = getMinValuePos(m).rowIndex;
    int row_max_el = getMaxValuePos(m).rowIndex;
    swapRows(m, row_max_el + 1, row_min_el + 1);
}

// максимальный и минимальный элементы
// в разных строках.
void test_swapRowsMinMaxElement_differentRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3, 4,
                    5, 6, 7, 8,
                    9, 10, 11, 12,
            },
            3, 4
    );
    swapRowsMinMaxElement(m);
    assert(m.values[0][0] == 9);
    assert(m.values[0][1] == 10);
    assert(m.values[0][2] == 11);
    assert(m.values[0][3] == 12);
    assert(m.values[2][0] == 1);
    assert(m.values[2][1] == 2);
    assert(m.values[2][2] == 3);
    assert(m.values[2][3] == 4);
    freeMemMatrix(&m);
}

// максимальный и минимальный элементы
// в одной строке.
void test_swapRowsMinMaxElement_sameRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 9,
                    3, 5,
                    8, 4,
            },
            3, 2
    );
    swapRowsMinMaxElement(m);
    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 9);
    assert(m.values[1][0] == 3);
    assert(m.values[1][1] == 5);
    assert(m.values[2][0] == 8);
    assert(m.values[2][1] == 4);
    freeMemMatrix(&m);
}

// возвращает самый большой элемент массива
int getMax(int *a, int n) {
    int max_el = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max_el)
            max_el = a[i];
    return max_el;
}

// Упорядочивает строки матрицы по
// неубыванию наибольших элементов строк.
void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

// различные максимальные элементы
void test_sortRowsByMaxElement_differentMaxElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 9,
                    3, 5,
                    8, 4,
            },
            3, 2
    );
    sortRowsByMaxElement(m);
    assert(m.values[0][0] == 3);
    assert(m.values[0][1] == 5);
    assert(m.values[1][0] == 8);
    assert(m.values[1][1] == 4);
    assert(m.values[2][0] == 1);
    assert(m.values[2][1] == 9);
    freeMemMatrix(&m);
}

// все максимальные элементы одинаковые
void test_sortRowsByMaxElement_allSameMaxElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 8,
                    3, 8,
                    8, 4,
            },
            3, 2
    );
    sortRowsByMaxElement(m);
    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 8);
    assert(m.values[1][0] == 3);
    assert(m.values[1][1] == 8);
    assert(m.values[2][0] == 8);
    assert(m.values[2][1] == 4);
    freeMemMatrix(&m);
}

// некоторые максимальные элементы одинаковые
void test_sortRowsByMaxElement_someSameMaxElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 8, 12,
                    3, 8, 6,
                    7, 4, 8,
            },
            3, 3
    );
    sortRowsByMaxElement(m);
    assert(m.values[0][0] == 3);
    assert(m.values[0][1] == 8);
    assert(m.values[0][2] == 6);
    assert(m.values[1][0] == 7);
    assert(m.values[1][1] == 4);
    assert(m.values[1][2] == 8);
    assert(m.values[2][0] == 1);
    assert(m.values[2][1] == 8);
    assert(m.values[2][2] == 12);
    freeMemMatrix(&m);
}

// возвращает минимальный элемент массива
int getMin(int *a, int n) {
    int min_el = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] < min_el)
            min_el = a[i];
    return min_el;
}

// Упорядочивает столбцы матрицы по
// неубыванию наименьших элементов столбцов.
void sortColsByMinElement(matrix m) {
    selectionSortColsMatrixByColCriteria(m, getMin);
}

// все минимальные элементы разные
void test_sortColsByMinElement_differentMinElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 8, 12, 2, 4,
                    8, 16, 5, 17, 32,
                    1, 9, 3, 12, 7,
            },
            3, 5
    );
    sortColsByMinElement(m);
    assert(m.values[0][0] == 3);
    assert(m.values[0][1] == 2);
    assert(m.values[0][2] == 12);
    assert(m.values[0][3] == 4);
    assert(m.values[0][4] == 8);
    assert(m.values[1][0] == 8);
    assert(m.values[1][1] == 17);
    assert(m.values[1][2] == 5);
    assert(m.values[1][3] == 32);
    assert(m.values[1][4] == 16);
    assert(m.values[2][0] == 1);
    assert(m.values[2][1] == 12);
    assert(m.values[2][2] == 3);
    assert(m.values[2][3] == 7);
    assert(m.values[2][4] == 9);
    freeMemMatrix(&m);
}

// некоторые минимальные элементы одинаковые
void test_sortColsByMinElement_someSameMinElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 8, 1, 2,
                    14, 4, 5, 9,
            },
            2, 4
    );
    sortColsByMinElement(m);
    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 2);
    assert(m.values[0][2] == 8);
    assert(m.values[0][3] == 7);
    assert(m.values[1][0] == 5);
    assert(m.values[1][1] == 9);
    assert(m.values[1][2] == 4);
    assert(m.values[1][3] == 14);
    freeMemMatrix(&m);
}

// возвращает результат умножения двух квадратных матриц
matrix mulSquareMatrices(matrix m1, matrix m2) {
    matrix m = getMemMatrix(m1.nRows, m2.nCols);
    for (int i = 0; i < m2.nRows; i++)
        for (int j = 0; j < m2.nCols; j++) {
            int element = 0;
            for (int k = 0; k < m1.nCols; k++) {
                element += m1.values[i][k] * m2.values[k][j];
            }
            m.values[i][j] = element;
        }
    return m;
}

// заменяет матрицу A квадратом, если матрица А симмметрична
void getSquareOfMatrixIfSymmetric(matrix *m) {
    if (isSymmetricMatrix(m)) {
        matrix m2 = mulSquareMatrices(*m, *m);
        for (int i = 0; i < m2.nRows; i++)
            for (int j = 0; j < m2.nCols; j++)
                m->values[i][j] = m2.values[i][j];
    }
}

// матрица симметрична
void test_getSquareOfMatrixIfSymmetric_symmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 0, 5,
                    3, 5, 1,
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m);
    assert(m.values[0][0] == 14);
    assert(m.values[0][1] == 17);
    assert(m.values[0][2] == 16);
    assert(m.values[1][0] == 17);
    assert(m.values[1][1] == 29);
    assert(m.values[1][2] == 11);
    assert(m.values[2][0] == 16);
    assert(m.values[2][1] == 11);
    assert(m.values[2][2] == 35);
    freeMemMatrix(&m);
}

// матрица не симметрична
void test_getSquareOfMatrixIfSymmetric_notSymmetricMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    8, 2, 5,
                    4, 7, 1,
            },
            3, 3
    );

    getSquareOfMatrixIfSymmetric(&m);
    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 2);
    assert(m.values[0][2] == 3);
    assert(m.values[1][0] == 8);
    assert(m.values[1][1] == 2);
    assert(m.values[1][2] == 5);
    assert(m.values[2][0] == 4);
    assert(m.values[2][1] == 7);
    assert(m.values[2][2] == 1);
    freeMemMatrix(&m);
}

// возвращает 1, если в массиве нет одинаковых элементов.
bool isUnique(long long *a, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] == a[j])
                return 0;
    return 1;
}

// возвращает сумму элементов массива.
long long getSum(int *a, int n) {
    long long res = 0;
    for (int i = 0; i < n; i++)
        res += a[i];
    return res;
}

// трпнспонирует матрицу, если среди сумм элементов
// строк матрицы нет равных.
void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    long long a[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        long long sum = getSum(m.values[i], m.nCols);
        a[i] = sum;
    }
    if (isUnique(a, m.nRows))
        transposeSquareMatrix(&m);
}

// разные суммы элементов строк.
void test_transposeIfMatrixHasNotEqualSumOfRows_notEqualSumOfRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );
    transposeIfMatrixHasNotEqualSumOfRows(m);
    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 3);
    assert(m.values[1][0] == 2);
    assert(m.values[1][1] == 4);
    freeMemMatrix(&m);
}

// одинаковые суммы элементов строк.
void test_transposeIfMatrixHasNotEqualSumOfRows_equalSumOfRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    5, 2,
                    3, 4,
            },
            2, 2
    );
    transposeIfMatrixHasNotEqualSumOfRows(m);
    assert(m.values[0][0] == 5);
    assert(m.values[0][1] == 2);
    assert(m.values[1][0] == 3);
    assert(m.values[1][1] == 4);
    freeMemMatrix(&m);
}

void test() {
    test_swapRowsMinMaxElement_differentRows();
    test_swapRowsMinMaxElement_sameRow();
    test_sortRowsByMaxElement_differentMaxElements();
    test_sortRowsByMaxElement_allSameMaxElements();
    test_sortRowsByMaxElement_someSameMaxElements();
    test_sortColsByMinElement_differentMinElements();
    test_sortColsByMinElement_someSameMinElements();
    test_getSquareOfMatrixIfSymmetric_symmetricMatrix();
    test_getSquareOfMatrixIfSymmetric_notSymmetricMatrix();
    test_transposeIfMatrixHasNotEqualSumOfRows_equalSumOfRows();
    test_transposeIfMatrixHasNotEqualSumOfRows_notEqualSumOfRows();
}

int main() {
    test();

    return 0;
}