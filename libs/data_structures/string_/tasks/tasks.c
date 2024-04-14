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