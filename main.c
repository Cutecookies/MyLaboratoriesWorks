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
}

void test() {
    test_swapRowsMinMaxElement_differentRows();
    test_swapRowsMinMaxElement_sameRow();
    test_sortRowsByMaxElement_differentMaxElements();
    test_sortRowsByMaxElement_allSameMaxElements();
    test_sortRowsByMaxElement_someSameMaxElements();
}

int main() {
    test();

    return 0;
}