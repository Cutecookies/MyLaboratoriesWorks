# include "stdlib.h"
# include "vector.h"
# include <stdio.h>

vector createVector(size_t n) {
    if (n == 0) {
        int *vector_data = {};
        return (vector) {vector_data, n, n};
    }
    int *vector_data = (int *) malloc(n * sizeof(int *));
    if (!vector_data) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vector) {vector_data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    if (newCapacity){
        if (v->data == NULL){
            v->data = malloc(newCapacity * sizeof(int));
        }
        else {
            int *new_data = malloc(newCapacity * sizeof(int));

            if (new_data == NULL) {
                fprintf(stderr, "bad alloc");
                exit(1);
            }

            if (new_data != v->data) {
                new_data = v->data;
                v->data = new_data;
            }

            if (v->size > newCapacity)
                v->size = newCapacity;
        }

        v->capacity = newCapacity;
    }
    else{
        v->size = 0;
        v->capacity = 0;
        v->data = NULL;
    }
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmpty(vector *v) {
    return v->size == 0;
}

bool isFull(vector *v) {
    return v->size == v->capacity;
}

int getVectorValue(vector *v, size_t i) {
    return v->data[i - 1];
}

void pushBack(vector *v, int x) {
    if (isFull(v))
        reserve(v, v->capacity * 2);
    v->data[v->size++] = x;
}

void popBack(vector *v) {
    if (isEmpty(v)) {
        fprintf(stderr, "empty array");
        exit(1);
    }

    v->size--;
}

int* atVector(vector *v, size_t index) {
    if (index >= v->size) {
        fprintf(stderr, "IndexError: a[%zu] is not exists", index);
        exit(1);
    }

    return v->data + index;
}

int* back(vector *v) {
    return v->data + (v->size - 1);
}

int* front(vector *v) {
    return v->data;
}