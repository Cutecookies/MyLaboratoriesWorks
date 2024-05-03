#ifndef LABORATORIESWORKS_STRING__H
#define LABORATORIESWORKS_STRING__H

# include "string.h"

// возвращает количество символов в строке
size_t strlen_(char *begin);

// возвращает указатель на первый элемент с кодом ch, расположенным
// на ленте памяти между адресами begin и end не включая end.
// Если символ не найден, возвращается значение end.
char *find(char *begin, char *end, int ch);

// возвращает указатель на первый символ, отличный от пробельных,
// расположенный на ленте памяти, начиная с begin и заканчивая ноль-символом.
// Если символ не найден, возвращается адрес первого ноль-символа.
char *findNonSpace(char *begin);

// возвращает указатель на первый пробельный символ,
// расположенный на ленте памяти начиная с адреса begin
// или на первый ноль-символ.
char *findSpace(char *begin);

// возвращает указатель на первый справа символ, отличный от пробельных.
// Если символ не найден, возвращается адрес rend.
char *findNonSpaceReverse(char *rbegin, const char *rend);

// возвращает указатель на первый пробельный символ справа.
// Если символ не найден, возвращается адрес rend.
char *findSpaceReverse(char *rbegin, const char *rend);

// возвращает отрицательное значение, если lhs располагается до rhs
// в лексикографическом порядке, значение 0, если lhs и rhs
// равны, иначе – положительное значение.
int strcmp_(const char *lhs, const char *rhs);

// записывает по адресу beginDestination фрагмент памяти,
// начиная с адреса beginSource до endSource
// Возвращает указатель на следующий свободный фрагмент
// памяти в destination.
char *copy(const char *beginSource, const char *endSource,
           char *beginDestination);

// записывает по адресу beginDestination элементы из фрагмента памяти,
// начиная с beginSource, заканчивая endSource,
// удовлетворяющие функции-предикату f.
// возвращает указатель на следующий свободный для записи
// фрагмент в памяти.
char* copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int));

// записывает по адресу beginDestination элементы из фрагмента памяти,
// начиная с rbeginSource, заканчивая rendSource,
// удовлетворяющие функции-предикату f.
// возвращает значение beginDestination по окончанию работы функции.
char* copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int));

// возвращает указатель на конец строки
char* getEndOfString(char *s);

// копирует строку src в drc
void strcpy_(char *dst, const char *src);

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100

extern char stringBuffer[MAX_STRING_SIZE + 1];

// task 1
void removeNonLetters(char *s);

// task 2
// Преобразует строку, оставляя только один символ в каждой
// последовательности подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s);

// task 3
typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после
    // последнего символа слова
} WordDescriptor;

// Преобразовать строку таким образом, чтобы цифры
// были в начале слова, а буквы в конце.
void digitToStartWithoutChange(WordDescriptor word);
// ищет слово
int getWord(char *beginSearch, WordDescriptor *word);

// ищет слово с конца
int getWordReverse(char *rbegin, char *rend, WordDescriptor *word);

// основная функция
void transformWord(char *beginString);

// task 4
void everyNumberBecomeSpaces(char *s);

// task 5
// возвращает 0, если слова одинаковые,
// -1, если rhs > lhs,
// 1, если rhs < lhs
int compareWords(WordDescriptor lhs, WordDescriptor rhs);

// возвращает указатель на конец скопированного слова
char *copyWord(char *s, WordDescriptor w);

// Заменяет все вхождения слова w1 на слово w2
void replace(char *source, char *w1, char *w2);

// task 6
int isWordsOrdered(char *s);

// task 7
typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

extern BagOfWords _bag;
extern BagOfWords _bag2;

// получает позиции начала и конца каждого слова строки
void getBagOfWords(BagOfWords *bag, char *s);

// выводит слово
void printWord(WordDescriptor w);

// вывод слов в обратном порядке
void printWordsFromEnd(char *s);

// task 8
// ищет слово
int getWordFromComma(char *beginSearch, WordDescriptor *word);

// слово - палиндром?
int isWordPalindrome(WordDescriptor w);

// возвращает количество слов-палиндромов в строке
int countWordsPalindromes(char *s);

// task 9

// записывает в 3 строку слова первой и второй строки, которые чередуются.
void uniteStrings(char *s1, char *s2, char *out);

// task 10

// Преобразовывает строку, изменив порядок следования слов в строке на обратный.
void makeStringWordReverse(char *s);

// task 11

typedef enum WordBeforeFirstWordWithAReturnCode {
    FIRST_WORD_WITH_A,
    NOT_FOUND_A_WORD_WITH_A,
    WORD_FOUND,
    EMPTY_STRING
} WordBeforeFirstWordWithAReturnCode;

// есть ли символ в слове
int isChInWord(WordDescriptor w, char a);

// заголовок функции
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
        char *s, WordDescriptor *w);

// task 12
// перевод WordDescriptor в char*.
void wordDescriptorToString(WordDescriptor word, char *destination);

// возвращает последнее из слов первой строки, которое есть во второй строке,
// в противном случае возвращает слово размером 0
WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2);

// task 13
int areThereSameWords(char *s);

// task 14

// функция сравнения
int compareChar(const void *c1, const void *c2);

// сортирует буквы в слове
void sortLettersInWord(WordDescriptor *w1);

// возвращает 1, если в данной строке есть пара слов,
// составленных из одинакового набора букв, в другом случае 0
int areWordsWithSameLetters(char *s);

// task 15

// создает Получить строку из слов данной строки,
// которые отличны от последнего слова.
void getStringFromWordsNotEqualTOLast(char *s);

// task 16

// возвращает слово, предшествующее первому вхождению w в s1.
WordDescriptor getWordBeforeW(char *s1, char *s2);

// task 17
// Удаляет из данной строки слова-палиндромы.
void deleteWordPalindromes(char *s);

//task 18
// заполнение строки словами из сумки
void fillStrWords(char *s, BagOfWords bag, size_t start_copy_index);

// дополняет строку, содержащую меньшее количество слов, последними
// словами строки, в которой содержится большее количество слов.
void fillString(char *s1, char *s2);

// task 19
// возвращает 1, если символ есть в строке, иначе - нет
int isSymbolInString(char *s, char c);

// возвращает 1, если в данную строку входит каждая
// буква данного слова, иначе - 0
int isAllLettersFromWordInString(char *s, WordDescriptor w);



#endif //LABORATORIESWORKS_STRING__H
