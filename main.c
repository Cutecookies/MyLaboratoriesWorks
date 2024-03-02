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

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    test();

    return 0;
}