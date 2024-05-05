# include "vectorVoid.h"
# include <stdio.h>
# include "stdlib.h"
# include <assert.h>

# include "string.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    if (n == 0) {
        void *vector_data = NULL;
        return (vectorVoid) {vector_data, n, n, baseTypeSize};
    }
    void *vector_data = (void *) malloc(n * baseTypeSize);
    if (!vector_data) {
        fprintf(stderr, "bad alloc");
        exit(1);
    }

    return (vectorVoid) {vector_data, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    if (newCapacity){
        if (v->data == NULL)
            v->data = malloc(newCapacity * v->baseTypeSize);
        else {
            void *new_data = malloc(newCapacity * v->baseTypeSize);

            if (new_data == NULL) {
                fprintf(stderr, "bad alloc");
                exit(1);
            }

            if (new_data != v->data)
                v->data = new_data;

            if (v->size > newCapacity)
                v->size = newCapacity;
        }

        v->capacity = newCapacity;
    }
    else
        deleteVectorV(v);
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

bool isEmptyV(vectorVoid *v) {
    return v->size == 0;
}

bool isFullV(vectorVoid *v) {
    return v->size == v->capacity;
}

void getVectorValueV(vectorVoid *v,
                     size_t index, void *destination) {
    assert(index < v->size);
    void *source = (void *) v->data + index * v->baseTypeSize;
    memcpy(destination, source, v->baseTypeSize);
}

void setVectorValueV(vectorVoid *v, size_t index, void *source) {
    memcpy(v->data + index * v->baseTypeSize,
           source, v->baseTypeSize);
}

void popBackV(vectorVoid *v) {
    if (isEmptyV(v)) {
        fprintf(stderr, "empty array");
        exit(1);
    }

    v->size--;
}

void pushBackV(vectorVoid *v, void *source) {
    if (isFullV(v)) {
        size_t newCapacity;
        if(v->capacity == 0)
            newCapacity = 1;
        else
            newCapacity = v->capacity * 2;

        reserveV(v, newCapacity);
    }
    memcpy(v->data + v->size * v->baseTypeSize,
           source, v->baseTypeSize);

    (v->size)++;
}