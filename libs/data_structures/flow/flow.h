#ifndef LABORATORIESWORKS_FLOW_H
#define LABORATORIESWORKS_FLOW_H

# include "../../data_structures/matrix/matrix.h"
# include "../../data_structures/vector/vectorVoid.h"
# include "../../data_structures/string_/string_.h"

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

// Task 5

// возвращает длину слова
int wordLen(WordDescriptor word);

// возвращает самое большое слово строки
WordDescriptor wordMaxLen(char *words);

// записывает слова в файл
void writeWords(char *filename, char *words[], int n);

// оставляет самые длинные слова в строчках
void onlyLongWords(char *filename);

// Task 6

// Структура для хранения многочлена
typedef struct Monomial {
    int degree;
    double coefficient;
} Monomial;

typedef struct Polynomial{
    int monomial_amount;
    Monomial *data;
} Polynomial;

// создание многочлена
Polynomial createPolynomialFromArray(const int degrees[],
                                     const double coefficients[],
                                     int amt_args);

// считывает многочлен из файла
Polynomial readPolynomialFromFile(FILE *file);

// считывает многочлены из файла
Polynomial* readPolynomialsFromFile(FILE *file, int *pol_amount);

// записывает многочлен в файл
void writePolynomialToFile(Polynomial p, FILE *file);

// записывает многочлены в файл
void writePolynomialsToFile(Polynomial *ps, FILE *file, int pol_amount);

// возвращает результат многочлена при x
double calculatePolynomial(Polynomial p, double x);

// освободить многочлен
void freePolynomial(Polynomial *p);

// освободить многочлены
void freePolynomials(Polynomial *ps, int pol_amount);

void onlyPolynomialWithoutRootX(char *filename, int x);

// Task 7

void positiveFirstNegativeLast(char *filename);

#endif //LABORATORIESWORKS_FLOW_H
