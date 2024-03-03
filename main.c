# include <assert.h>
# include "libs/data_structures/vector/vector.h"
# include "libs/data_structures/vector/vectorVoid.h"
# include "stdio.h"

// Вектор пустой
void test_pushBack_emptyVector() {
    vector v = createVector(6);
    pushBack(&v, 5);

    assert(v.size == 1);
    assert(v.data[0] == 5);
    assert(v.capacity == 6);
}

// Вектор заполнен
void test_pushBack_fullVector() {
    int vector_data[] = {1, 2, 3, 4};
    vector v = createVector(4);
    v.data = vector_data;
    v.size = 4;

    pushBack(&v, 5);
    assert(v.size == 4 + 1);
    assert(v.data[4] == 5);
    assert(v.capacity == 8);
}

// Вектор не пустой
void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

// Вектор не пустой
void test_atVector_notEmptyVector() {
    int vector_data[] = {1, 2, 3, 4};
    vector v = createVector(4);
    v.data = vector_data;
    v.size = 4;

    int* a = atVector(&v, 2);
    assert(a[0] == 3);
}

// Запрос на последний элемент
void test_atVector_requestToLastElement() {
    int vector_data[] = {1, 2, 3, 4};
    vector v = createVector(4);
    v.data = vector_data;
    v.size = 4;

    int* a = atVector(&v, 3);
    assert(a[0] == 4);
}

// Один элемент в векторе
void test_back_oneElementInVector() {
    int vector_data[] = {21};
    vector v = createVector(3);
    v.data = vector_data;
    v.size = 1;

    int* a = back(&v);
    assert(a[0] == 21);
}

// Несколько элементов в векторе
void test_back_manyElementsInVector() {
    int vector_data[] = {2, 7, 1};
    vector v = createVector(5);
    v.data = vector_data;
    v.size = 3;

    int* a = back(&v);
    assert(a[0] == 1);
}

// Один элемент в векторе
void test_front_oneElementInVector() {
    int vector_data[] = {35};
    vector v = createVector(3);
    v.data = vector_data;
    v.size = 1;

    int* a = front(&v);
    assert(a[0] == 35);
}

// Несколько элементов в векторе
void test_front_manyElementsInVector() {
    int vector_data[] = {3, 4, 5};
    vector v = createVector(5);
    v.data = vector_data;
    v.size = 3;

    int* a = front(&v);
    assert(a[0] == 3);
}

void test() {

}

int main() {
    size_t n;
    scanf("%zd", &n);
    vectorVoid v = createVectorV(0, sizeof(float));
    for (int i = 0; i < n; i++) {
        float x;
        scanf("%f", &x);
        pushBackV(&v, &x);
    }
    for (int i = 0; i < n; i++) {
        float x;
        getVectorValueV(&v, i, &x);
        printf("%f ", x);
    }

    return 0;
}