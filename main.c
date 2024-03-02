#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "libs/data_structures/vector/vector.h"

// Вектор пустой
void test_pushBack_emptyVector() {
    size_t vector_capacity = 6;
    vector v = createVector(vector_capacity);
    int x = 5;
    pushBack(&v, x);

    assert(v.size = 1);
    assert(v.data[0] = x);
    assert(vector_capacity == v.capacity);
}

// Вектор заполнен
void test_pushBack_fullVector() {
    size_t vector_capacity = 4;
    int vector_data[] = {1, 2, 3, 4};
    vector v = createVector(vector_capacity);
    v.data = vector_data;
    v.size = vector_capacity;

    int x = 5;
    pushBack(&v, x);
    assert(v.size = vector_capacity + 1);
    assert(v.data[vector_capacity] = x);
    assert(vector_capacity * 2 == v.capacity);
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
    size_t vector_capacity = 4;
    int vector_data[] = {1, 2, 3, 4};
    vector v = createVector(vector_capacity);
    v.data = vector_data;
    v.size = vector_capacity;

    int* a = atVector(&v, 2);
    assert(a[0] == 3);
}

// Запрос на последний элемент
void test_atVector_requestToLastElement() {
    size_t vector_capacity = 4;
    int vector_data[] = {1, 2, 3, 4};
    vector v = createVector(vector_capacity);
    v.data = vector_data;
    v.size = vector_capacity;

    int* a = atVector(&v, 3);
    assert(a[0] == 4);
}

// Один элемент в векторе
void test_back_oneElementInVector() {
    size_t vector_capacity = 3;
    int vector_data[] = {21};
    vector v = createVector(vector_capacity);
    v.data = vector_data;
    v.size = 1;

    int* a = back(&v);
    assert(a[0] == 21);
}

// Несколько элементов в векторе
void test_back_manyElementsInVector() {
    size_t vector_capacity = 5;
    int vector_data[] = {2, 7, 1};
    vector v = createVector(vector_capacity);
    v.data = vector_data;
    v.size = 3;

    int* a = back(&v);
    assert(a[0] == 1);
}

// Один элемент в векторе
void test_front_oneElementInVector() {
    size_t vector_capacity = 3;
    int vector_data[] = {35};
    vector v = createVector(vector_capacity);
    v.data = vector_data;
    v.size = 1;

    int* a = front(&v);
    assert(a[0] == 35);
}

// Несколько элементов в векторе
void test_front_manyElementsInVector() {
    size_t vector_capacity = 5;
    int vector_data[] = {3, 4, 5};
    vector v = createVector(vector_capacity);
    v.data = vector_data;
    v.size = 3;

    int* a = front(&v);
    assert(a[0] == 3);
}

void test() {
    test_atVector_notEmptyVector();
    test_atVector_requestToLastElement();
    test_back_oneElementInVector();
    test_back_manyElementsInVector();
    test_front_oneElementInVector();
    test_front_manyElementsInVector();
}

int main() {
    test();

    return 0;
}