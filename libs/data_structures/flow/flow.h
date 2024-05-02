#ifndef LABORATORIESWORKS_FLOW_H
#define LABORATORIESWORKS_FLOW_H

# include "../../data_structures/matrix/matrix.h"
# include "../../data_structures/vector/vectorVoid.h"

//Task 1

// создание файла с матрицами
void createFileWithMatrices(char *filename);

// Преобразовывает файл так, чтобы
// элементы матрицы хранились по столбцам
void transposeAllMatricesInFile(char *filename);

// Task 2

// создание файла с вещественными числами
void createFileWithFloatNumbers(char *filename);

// чтение вещественных чисел и запись в vectorVoid
vectorVoid readFloatNumbersFromFile(char *filename);

// запись вещественных чисел и запись в vectorVoid
void writeFloatNumbersFromFile(char *filename, float *numbers, int amt_n);

// Преобразовывает файл, представив каждое число
// в форме с плавающей точкой, сохранив две цифры
// после точки в мантиссе.
void convertNumbersToFloatingPoint(char *filename);

// Task 3

// запись операции в файл
void writeOperation(char *filename, float *operands, char *operations,
                    int amt_op);

// возвращает результат операции над двумя числами
float makeOperation(float n1, float n2, char op);

// запись операции и ответа
void writeOperationAndAnswer(char *filename, float *operands, char *operations,
                             int amt_op, float answer);

// записывает ответ после примера
void solveExample(char *filename);

// Task 4

// 1 - строки равны, 0 - нет
int compareStr(const char *w1, const char *w2, long n);

// возвращает размер файла
long getFileSize(const char* filename);

// записывает слова в файл
void writeWordsInFile(char *filename, char words[100][100], int amt_w);

// записывает буфер в файл
void writeBufferInFile(char *filename, char *buf);

// Сохраняет в файле только те слова, которые
// содержат данную последовательность символов.
void leftWordsWithSymbols(char *filename, const char *symbols);

#endif //LABORATORIESWORKS_FLOW_H
