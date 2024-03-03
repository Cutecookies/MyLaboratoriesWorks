#ifndef LABORATORIESWORKS_VECTORVOID_H
#define LABORATORIESWORKS_VECTORVOID_H

# include "stdbool.h"
#include <limits.h>
typedef struct vectorVoid {
    void *data;          // указатель на нулевой элемент вектора
    size_t size;         // размер вектора
    size_t capacity;     // вместимость вектора
    size_t baseTypeSize; // размер базового типа:
                         // например, если вектор хранит int -
                         // то поле baseTypeSize = sizeof(int)
                         // если вектор хранит float -
                         // то поле baseTypeSize = sizeof(float)

} vectorVoid;

// возвращает структуру vectorVoid из n значений с
// базовым типом baseTypeSize.
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// изменяет количество памяти, выделенное
// под хранение элементов вектора.
void reserveV(vectorVoid *v, size_t newCapacity);

// освобождает память, выделенную под
// неиспользуемые элементы.
void shrinkToFitV(vectorVoid *v);

// удаляет элементы из контейнера, но не
// освобождает выделенную память.
void clearV(vectorVoid *v);

// освобождает память, выделенную вектору.
void deleteVectorV(vectorVoid *v);

// является ли вектор пустым.
bool isEmptyV(vectorVoid *v);

// является ли вектор полным.
bool isFullV(vectorVoid *v);

// записывает по адресу destination index-ый элемент вектора v.
void getVectorValueV(vectorVoid *v,
                     size_t index, void *destination);

// удаляет последний элемент из вектора.
void popBackV(vectorVoid *v);

// добавляет source в конец вектора v.
void pushBackV(vectorVoid *v, void *source);

#endif //LABORATORIESWORKS_VECTORVOID_H
