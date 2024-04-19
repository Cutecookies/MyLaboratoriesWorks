# include "../string_.h"
# include <ctype.h>
# include "stdio.h"

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20

char stringBuffer[MAX_STRING_SIZE + 1];

// task 1
void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

// task 2
// Преобразует строку, оставляя только один символ в каждой
// последовательности подряд идущих одинаковых символов
void removeAdjacentEqualLetters(char *s) {
    char *copy_s = s;
    char *end_s = getEndOfString(copy_s);
    while (*copy_s != *end_s) {
        if (*copy_s != *(copy_s + 1)) {
            *s = *copy_s;
            s++;
        }
        copy_s++;
    }
    *s = '\0';
}

// task 3
typedef struct WordDescriptor {
    char *begin; // позиция начала слова
    char *end; // позиция первого символа, после
    // последнего символа слова
} WordDescriptor;

// Преобразовать строку таким образом, чтобы цифры
// были в начале слова, а буквы в конце.
void digitToStartWithoutChange(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 stringBuffer);

    char *recPosition = copyIf(stringBuffer,
                               endStringBuffer,
                               word.begin, isdigit);
    copyIf(stringBuffer, endStringBuffer, recPosition, isalpha);
}

// ищет слово
int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0')
        return 0;
    word->end = findSpace(word->begin);
    return 1;
}

// ищет слово с конца
int getWordReverse(char *rbegin, char *rend, WordDescriptor *word) {
    word->end = findNonSpaceReverse(rbegin, rend);
    if (*word->end == *rend)
        return 0;
    word->begin = findSpaceReverse(word->end, rend);
    return 1;
}

// основная функция
void transformWord(char *beginString) {
    char *beginSearch = beginString;
    WordDescriptor word; // считываемое слово
    while (getWord(beginSearch, &word)) {
        digitToStartWithoutChange(word);
        beginSearch = word.end;
    }
}

// task 4
void everyNumberBecomeSpaces(char *s) {
    char *copy_s = stringBuffer;
    strcpy_(copy_s, s);
    char *end_s = getEndOfString(copy_s);

    while (copy_s != end_s) {
        char symbol = *copy_s;
        if (isdigit(symbol)) {
            int num = symbol - '0';
            while (num > 0) {
                *s = ' ';
                s++;
                num -= 1;
            }
        } else {
            *s = symbol;
            s++;
        }
        copy_s++;
    }
    *s = '\0';
}

// task 5
// возвращает 0, если слова одинаковые,
// -1, если rhs > lhs,
// 1, если rhs < lhs
int compareWords(WordDescriptor lhs, WordDescriptor rhs) {
    while (*lhs.begin == *rhs.begin && lhs.begin != lhs.end) {
        lhs.begin++;
        rhs.begin++;
    }
    if (lhs.begin == lhs.end && rhs.begin == rhs.end)
        return 0;
    if (lhs.begin == lhs.end)
        lhs.begin--;
    if (rhs.begin == rhs.end)
        rhs.begin--;
    return *lhs.begin < *rhs.begin ? -1 : 1;
}

// возвращает указатель на конец скопированного слова
char *copyWord(char *s, WordDescriptor w) {
    return copy(w.begin, w.end, s);
}

// Заменяет все вхождения слова w1 на слово w2
void replace(char *source, char *w1, char *w2) {
    if (*source == 0)
        return;
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *recPtr;

    if (w1Size >= w2Size) {
        readPtr = source;
        recPtr = source;
    } else {
        copy(source, getEndOfString(source), stringBuffer);
        readPtr = stringBuffer;
        recPtr = source;
    }

    WordDescriptor word;
    while (getWord(readPtr, &word)) {
        if (!compareWords(word, word1))
            recPtr = copyWord(recPtr, word2);
        else
            recPtr = copyWord(recPtr, word);
        *recPtr = ' ';
        recPtr++;
        readPtr = word.end;
    }

    *(recPtr - 1) = '\0';
}

// task 6
int isWordsOrdered(char *s) {
    WordDescriptor w1;
    if (getWord(s, &w1))
        while (*w1.end != '\0') {
            WordDescriptor w2;
            getWord(w1.end, &w2);
            if (compareWords(w1, w2) > 0)
                return 0;
            w1 = w2;
        }
    return 1;
}

// task 7
typedef struct BagOfWords {
    WordDescriptor words[MAX_N_WORDS_IN_STRING];
    size_t size;
} BagOfWords;

BagOfWords _bag;
BagOfWords _bag2;

// получает позиции начала и конца каждого слова строки
void getBagOfWords(BagOfWords *bag, char *s) {
    WordDescriptor word;
    bag->size = 0;
    while (getWord(s, &word)) {
        s = word.end;
        bag->words[bag->size++] = word;
    }
}

// выводит слово
void printWord(WordDescriptor w) {
    while(w.begin != w.end) {
        putchar(*w.begin);
        w.begin++;
    }
}

// вывод слов в обратном порядке
void printWordsFromEnd(char *s) {
    getBagOfWords(&_bag, s);
    for (int i = _bag.size - 1; i >= 0; i--) {
        printWord(_bag.words[i]);
        putchar(' ');
    }
}