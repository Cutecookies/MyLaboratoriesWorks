# include "vectorVoid.h"
# include <stdio.h>
# include "stdlib.h"

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    if (n == 0) {
        void *vector_data = {};
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

            if (new_data != v->data) {
                new_data = v->data;
                v->data = new_data;
            }

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