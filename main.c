# include <assert.h>
# include "libs/data_structures/matrix/matrix.h"
# include "stdio.h"
#include "math.h"
# include "stdlib.h"

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

// возвращает 1, если матрицы являются
// взаимно обратными
bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    assert(m1.nRows == m2.nRows);
    matrix m = mulSquareMatrices(m1, m2);
    return isEMatrix(&m);
}

// матрицы являются взаимно обратными
void test_isMutuallyInverseMatrices_true() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 5,
            },
            2, 2
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    -5, 2,
                    3, -1,
            },
            2, 2
    );

    assert(isMutuallyInverseMatrices(m1, m2));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

// матрицы не являются взаимно обратными
void test_isMutuallyInverseMatrices_false() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 4,
            },
            2, 2
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    5, 6,
                    7, 8,
            },
            2, 2
    );

    assert(!(isMutuallyInverseMatrices(m1, m2)));
    freeMemMatrix(&m1);
    freeMemMatrix(&m2);
}

// возвращает максимальное из двух чисел.
int max(int a, int b) {
    return a > b ? a : b;
}

// возвращает сумму максимальных элементов всех
// псевдодиагоналей данной матрицы.
long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long s = 0;
    for (int j = 1; j < m.nCols; j++) {
        int row = 0;
        int col = j;
        int max_num = m.values[row][j];
        while (row < m.nRows && col < m.nCols) {
            max_num = max(max_num, m.values[row][col]);
            row += 1;
            col += 1;
        }
        s += max_num;
    }
    for (int i = 1; i < m.nRows; i++) {
        int row = i;
        int col = 0;
        int max_num = m.values[i][col];
        while (row < m.nRows && col < m.nCols) {
            max_num = max(max_num, m.values[row][col]);
            row += 1;
            col += 1;
        }
        s += max_num;
    }

    return s;
}

void test_findSumOfMaxesOfPseudoDiagonal() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 7, 3,
                    3, 4, 5, 8,
                    2, 6, 9, 1,
            },
            3, 4
    );
    long long s = findSumOfMaxesOfPseudoDiagonal(m);
    assert(s == 24);
}

// возвращает минимальный элемент
// матрицы в выделенной области.
int getMinInArea(matrix m) {
    position max_el = getMaxValuePos(m);
    int row = max_el.rowIndex - 1;
    int col = max_el.colIndex - 1;
    int length = 3;
    int min_el = m.values[max_el.rowIndex][max_el.colIndex];
    while (row >= 0) {
        int min = getMin(m.values[row] + col, length);
        row -= 1;
        col -= 1;
        length += 2;
        if (length > m.nCols)
            length = m.nCols;
        if (min < min_el)
            min_el = min;
    }

    return min_el;
}

// в выделенной области несколько элементов.
void test_getMinInArea_someElements() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 7, 5, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2,
            },
            3, 4
    );

    int min = getMinInArea(m);
    assert(min == 5);
    freeMemMatrix(&m);
}

// в выделенной области один элемент.
void test_getMinInArea_oneElement() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    10, 7, 22, 6,
                    3, 11, 8, 9,
                    4, 1, 12, 2,
            },
            3, 4
    );

    int min = getMinInArea(m);
    assert(min == 22);
    freeMemMatrix(&m);
}

// возвращает дистанцию.
float getDistance(int *a, int n) {
    float dist = 0;
    for (int i = 0; i < n; i++) {
        dist += pow(a[i], 2);
    }
    return pow(dist, 0.5);
}

// сортирует строки матрицы по неубыванию по значению критерия float
void insertionSortRowsMatrixByRowCriteriaF(matrix m,
                                           float (*criteria)(int *, int)) {
    float criteria_res[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        float temp = criteria(m.values[i], m.nCols);
        criteria_res[i] = temp;
    }

    for (int i = 1; i < m.nRows; i++) {
        float temp = criteria_res[i];
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

// Упорядочивает точки по неубыванию их
// расстояний до начала координат.
void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

void test_sortByDistances() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    12, 5, //13
                    3, 4,  //5
                    9, 12, //15
            },
            3, 2
    );
    sortByDistances(m);
    assert(m.values[0][0] == 3);
    assert(m.values[0][1] == 4);
    assert(m.values[1][0] == 12);
    assert(m.values[1][1] == 5);
    assert(m.values[2][0] == 9);
    assert(m.values[2][1] == 12);
    freeMemMatrix(&m);
}

// возвращает -1, если pa < pb,
// 0, если pa == pb,
// и 1 в противном случае.
int cmp_long_long(const void *pa, const void *pb) {
    if (pa < pb)
        return -1;
    if (pa == pb)
        return 0;
    return 1;
}

// возвращает количество уникальных элементов массива.
int countNUnique(long long *a, int n) {
    int amt_unique = 0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1)
            amt_unique += 1;
        else if (a[i] != a[i + 1])
            amt_unique += 1;
    }
    return amt_unique;
}

// возвращает количество классов эквивалентных
// строк данной прямоугольной матрицы.
int countEqClassesByRowsSum(matrix m) {
    long long a[m.nRows];
    for (int i = 0; i < m.nRows; i++) {
        a[i] = getSum(m.values[i], m.nCols);
    }
    qsort(a, m.nRows, sizeof(long long), cmp_long_long);
    return countNUnique(a, m.nRows);
}

void test_countEqClassesByRowsSum() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 9,
                    7, 3,
                    2, 4,
                    7, 1,
                    1, 2,
            },
            5, 2
    );
    assert(countEqClassesByRowsSum(m) == 4);
    freeMemMatrix(&m);
}

// возвращает количество "особых" элементов матрицы.
int getNSpecialElement(matrix m) {
    transposeMatrix(&m);
    int amt_special = 0;
    for (int i = 0; i < m.nRows; i++) {
        long long sum = getSum(m.values[i], m.nCols);
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] > sum - m.values[i][j])
                amt_special++;
    }
    return amt_special;
}

// матрица квадратная.
void test_getNSpecialElement_squareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 23, 6,
                    12, 2, 1,
            },
            3, 3
    );
    assert(getNSpecialElement(m) == 3);
    freeMemMatrix(&m);

}

// матрица не квадратная.
void test_getNSpecialElement_rectangleMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2,
            },
            3, 4
    );
    assert(getNSpecialElement(m) == 2);
    freeMemMatrix(&m);
}

// возвращает координаты самого левого минимального числа.
position getLeftMin(matrix m) {
    transposeSquareMatrix(&m);
    position pos = getMinValuePos(m);
    transposeSquareMatrix(&m);
    return pos;
}

// Заменяет n строку матрицы
// первым из столбцов, в котором находится
// минимальный элемент матрицы.
void swapPenultimateRow(matrix m, int n) {
    int col_ind = getLeftMin(m).colIndex;
    transposeSquareMatrix(&m);
    int col[m.nRows];
    for (int i = 0; i < m.nRows; i++)
        col[i] = m.values[col_ind][i];
    transposeSquareMatrix(&m);
    for (int i = 0; i < m.nCols; i++)
        m.values[n - 1][i] = col[i];
}

void test_swapPenultimateRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 23, 6,
                    12, 2, 1,
            },
            3, 3
    );
    swapPenultimateRow(m, 2);
    assert(m.values[0][0] == 1);
    assert(m.values[0][1] == 2);
    assert(m.values[0][2] == 3);
    assert(m.values[1][0] == 1);
    assert(m.values[1][1] == 2);
    assert(m.values[1][2] == 12);
    assert(m.values[2][0] == 12);
    assert(m.values[2][1] == 2);
    assert(m.values[2][2] == 1);
    freeMemMatrix(&m);
}

// возвращает 1, если массив отсортирован по неубыванию.
bool isNonDescendingSorted(const int *a, int n) {
    for (int i = 0; i < n - 1; i++)
        if (a[i] > a[i + 1])
            return 0;
    return 1;
}

// возвращает 1, если все строки матрицы отсортированы.
bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!(isNonDescendingSorted(m.values[i], m.nCols)))
            return 0;
    return 1;
}

// возвращает число матриц, строки которых
// упорядочены по неубыванию элементов.
int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int amt_matrices = 0;
    for (int i = 0; i < nMatrix; i++)
        if (hasAllNonDescendingRows(ms[i]))
            amt_matrices += 1;
    return amt_matrices;
}

void test_countNonDescendingRowsMatrices() {
    matrix *m = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1, 1, 1,
                    1, 6, 2, 2,
                    5, 4, 2, 3,
                    1, 3, 7, 9,
            },
            4, 2, 2
    );
    assert(countNonDescendingRowsMatrices(m, 4) == 2);
    freeMemMatrices(m, 4);
}

// возвращает количество value в массиве.
int countValues(const int *a, int n, int value) {
    int amt = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == value)
            amt += 1;
    return amt;
}

// возвращает количество нулевых строк.
int countZeroRows(matrix m) {
    int amt = 0;
    for (int i = 0; i < m.nRows; i++)
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            amt += 1;
    return amt;
}

// Выводит матрицы, имеющие наибольшее число нулевых строк.
void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int amt_zero_rows[nMatrix];
    for (int i = 0; i < nMatrix; i++)
        amt_zero_rows[i] = countZeroRows(ms[i]);
    int max = getMax(amt_zero_rows, nMatrix);
    for (int i = 0; i < nMatrix; i++)
        if (amt_zero_rows[i] == max) {
            outputMatrix(ms[i]);
            printf("\n");
        }
}

void test_printMatrixWithMaxZeroRows() {
    matrix *m = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 1, 1, 0, 0, 0,
                    1, 1, 2, 1, 1, 1,
                    0, 0, 0, 0, 4, 7,
                    0, 0, 0, 1, 0, 0,
                    0, 1, 0, 2, 0, 3,
            },
            5, 3, 2
    );
    printMatrixWithMaxZeroRows(m, 5);
    freeMemMatrices(m, 5);
}

void test_countZeroRows() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0,
                    1, 23, 6,
                    0, 0, 0,
            },
            3, 3
    );
    assert(countZeroRows(m) == 2);
    freeMemMatrix(&m);
}

// возвращает норму матрицы.
int getNormOfMatrix(matrix m) {
    int norm = 0;
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (abs(m.values[i][j]) > norm)
                norm = abs(m.values[i][j]);
    return norm;
}

// Выводит матрицы с наименьшей нормой.
void printMatrixWithMinNorm(matrix *ms, int nMatrix) {
    int norms[nMatrix];
    for (int i = 0; i < nMatrix; i++)
        norms[i] = getNormOfMatrix(ms[i]);
    int min = getMin(norms, nMatrix);
    for (int i = 0; i < nMatrix; i++)
        if (norms[i] == min) {
            outputMatrix(ms[i]);
            printf("\n");
        }
}

void test_printMatrixWithMinNorm() {
    matrix *m = createArrayOfMatrixFromArray(
            (int[]) {
                    1, -3, 5, 4,
                    7, 3, 15, 9,
                    2, -5, 3, 1,
            },
            3, 2, 2
    );
    printMatrixWithMinNorm(m, 3);
    freeMemMatrices(m, 3);
}

void test_getNormOfMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, -3, 4,
                    7, 3, 6,
                    5, -8, -1,
            },
            3, 3
    );
    assert(getNormOfMatrix(m) == 8);
    freeMemMatrix(&m);
}

// возвращает минимальный из двух элементов.
int min2(int a, int b) {
    return a < b? a: b;
}

// возвращает 1, если эдемент "особый".
bool isSpecial(int *a, int n, int special_ind) {
    for (int i = 0; i < special_ind; i++) {
        if (min2(a[i], a[special_ind]) != a[i])
            return 0;
    }
    for (int i = special_ind + 1; i < n; i++) {
        if (min2(a[i], a[special_ind]) == a[i])
            return 0;
    }
    return 1;
}

// возвращает количество "особых" элементов данной матрицы.
int getNSpecialElement2(matrix m) {
    int k = 0;
    for (int row = 0; row < m.nRows; row++)
        for (int col = 0; col < m.nCols; col++)
            if (isSpecial(m.values[row], m.nCols, col))
                k += 1;
    return k;
}

void test_getNSpecialElement2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 3, 5, 5, 4,
                    6, 2, 3, 8, 12,
                    12, 12, 2, 1, 1,
            },
            3, 5
    );
    assert(getNSpecialElement2(m) == 4);
    freeMemMatrix(&m);
}

void test_isSpecial() {
    int array[] = {1, 3, 3, 4, 2, 5};
    assert(isSpecial(array, 6, 0));
    assert(!isSpecial(array, 6, 3));
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
    test_isMutuallyInverseMatrices_true();
    test_isMutuallyInverseMatrices_false();
    test_findSumOfMaxesOfPseudoDiagonal();
    test_getMinInArea_someElements();
    test_getMinInArea_oneElement();
    test_sortByDistances();
    test_countEqClassesByRowsSum();
    test_getNSpecialElement_squareMatrix();
    test_getNSpecialElement_rectangleMatrix();
    test_swapPenultimateRow();
}

void test_1() {
    test_countNonDescendingRowsMatrices();
    test_countZeroRows();
    test_printMatrixWithMaxZeroRows();
    test_printMatrixWithMinNorm();
    test_getNormOfMatrix();
    test_getNSpecialElement2();
    test_isSpecial();
}

int main() {
    test_1();

    return 0;
}