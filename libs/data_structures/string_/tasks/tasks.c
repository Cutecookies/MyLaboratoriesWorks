# include "../string_.h"
# include <ctype.h>
# include "stdio.h"
# include "stdbool.h"
# include "stdlib.h"

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
    if (word->end == rend)
        return 0;
    word->begin = findSpaceReverse(word->end, rend) + 1;
    word->end++;
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
    while (w.begin != w.end) {
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

// task 8
// ищет слово
int getWordFromComma(char *beginSearch, WordDescriptor *word) {
    word->begin = beginSearch;
    if (*word->begin == '\0')
        return 0;
    word->end = word->begin;
    while (*word->end != ',' && *word->end != '\0')
        word->end++;
    return 1;
}

// слово - палиндром?
int isWordPalindrome(WordDescriptor w) {
    w.end--;
    while (w.begin < w.end) {
        if (*w.begin != *w.end)
            return 0;
        w.begin++;
        w.end--;
    }
    return 1;
}

// возвращает количество слов-палиндромов в строке
int countWordsPalindromes(char *s) {
    WordDescriptor word;
    int amount_palindromes = 0;
    while (getWordFromComma(s, &word)) {
        amount_palindromes += isWordPalindrome(word);
        s = word.end;
        if (*word.end == ',')
            s++;
    }
    return amount_palindromes;
}

// task 9

// записывает в 3 строку слова первой и второй строки, которые чередуются.
void uniteStrings(char *s1, char *s2, char *out) {
    if (*s1 == '\0' && *s2 == '\0') {
        *out = '\0';
        return;
    }
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {
        if (isW1Found) {
            out = copyWord(out, word1);
            beginSearch1 = word1.end;
            *(out++) = ' ';
        }
        if (isW2Found) {
            out = copyWord(out, word2);
            beginSearch2 = word2.end;
            *(out++) = ' ';
        }
    }
    *(out - 1) = '\0';
}

// task 10

// Преобразовывает строку, изменив порядок следования слов в строке на обратный.
void makeStringWordReverse(char *s) {
    if (*s == '\0')
        return;
    char *copy_s = stringBuffer;
    strcpy_(copy_s, s);
    char *end_s = getEndOfString(copy_s) - 1;

    WordDescriptor word;
    while (getWordReverse(end_s, copy_s - 1, &word)) {
        s = copyWord(s, word);
        *s = ' ';
        s++;
        end_s = word.begin - 1;
    }
    *(s - 1) = '\0';
}

// task 11

// есть ли символ в слове
int isChInWord(WordDescriptor w, char a) {
    return find(w.begin, w.end, a) != w.end;
}

// заголовок функции
WordBeforeFirstWordWithAReturnCode getWordBeforeFirstWordWithA(
        char *s, WordDescriptor *w) {
    if (!getWord(s, w))
        return EMPTY_STRING;
    if (isChInWord(*w, 'a') || isChInWord(*w, 'A'))
        return FIRST_WORD_WITH_A;
    WordDescriptor word;
    while (getWord(w->end, &word)) {
        if (isChInWord(word, 'a') || isChInWord(word, 'A'))
            return WORD_FOUND;
        *w = word;
    }
    return NOT_FOUND_A_WORD_WITH_A;
}

// task 12
// перевод WordDescriptor в char*.
void wordDescriptorToString(WordDescriptor word, char *destination) {
    while (word.begin != word.end) {
        *destination = *word.begin;
        word.begin++;
        destination++;
    }
    *destination = '\0';
}

// возвращает последнее из слов первой строки, которое есть во второй строке,
// в противном случае возвращает слово размером 0
WordDescriptor lastWordInFirstStringInSecondString(char *s1, char *s2) {
    WordDescriptor word;
    if (*s1 == '\0' || *s2 == '\0') {
        return (WordDescriptor) {NULL, NULL};
    }
    getBagOfWords(&_bag2, s2);
    char *end_s1 = getEndOfString(s1) - 1;
    while (getWordReverse(end_s1, s1 - 1, &word)) {
        for (int i = 0; i < _bag2.size; i++)
            if (compareWords(_bag2.words[i], word) == 0)
                return word;
        end_s1 = word.begin - 1;
    }
    return (WordDescriptor) {NULL, NULL};
}

// task 13
int areThereSameWords(char *s) {
    char *copy_s = stringBuffer;
    strcpy_(copy_s, s);

    WordDescriptor w1;
    WordDescriptor w2;
    while (getWord(s, &w1)) {
        copy_s = w1.end + 1;
        while (getWord(copy_s, &w2)) {
            if (compareWords(w1, w2) == 0)
                return 1;
            copy_s = w2.end;
        }
        s = w1.end;
    }
    return 0;
}

// task 14

// функция сравнения
int compareChar(const void *c1, const void *c2) {
    return *((char *) c1) - *((char *) c2);
}

// сортирует буквы в слове
void sortLettersInWord(WordDescriptor *w1) {
    qsort(w1->begin, w1->end - w1->begin, sizeof(char), compareChar);
}

// возвращает 1, если в данной строке есть пара слов,
// составленных из одинакового набора букв, в другом случае 0
int areWordsWithSameLetters(char *s) {
    char *copy_s = stringBuffer;
    strcpy_(copy_s, s);

    WordDescriptor word;
    while (getWord(s, &word)) {
        sortLettersInWord(&word);
        copy(word.begin, word.begin, s);
        s = word.end;
    }
    return areThereSameWords(copy_s);
}

// task 15

// создает Получить строку из слов данной строки,
// которые отличны от последнего слова.
void getStringFromWordsNotEqualTOLast(char *s) {
    if (*s == '\0')
        return;
    WordDescriptor last_word;
    char *s_end = getEndOfString(s) - 1;
    getWordReverse(s_end, s - 1, &last_word);
    char *wr = s;
    char *r = s;

    WordDescriptor word;
    while (getWord(r, &word)) {
        if (compareWords(word, last_word) != 0) {
            wr = copy(word.begin, word.end, wr);
            *wr = ' ';
            wr++;
        }
        r = word.end;
    }
    if (wr != s) {
        wr--;
    }
    *wr = '\0';
}

// task 16

// возвращает слово, предшествующее первому вхождению w в s1.
WordDescriptor getWordBeforeW(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);

    for (size_t i = 0; i < _bag.size; i++)
        for (size_t j = 0; j < _bag2.size; j++)
            if (compareWords(_bag.words[i], _bag2.words[j]) == 0) {
                if (i == 0)
                    return (WordDescriptor) {NULL, NULL};
                return _bag.words[i - 1];
            }
    return (WordDescriptor) {NULL, NULL};
}

// task 17
// Удаляет из данной строки слова-палиндромы.
void deleteWordPalindromes(char *s) {
    char *r = s;
    char *wr = s;
    WordDescriptor word;
    while (getWord(r, &word)) {
        if (!isWordPalindrome(word)) {
            wr = copyWord(wr, word);
            *wr = ' ';
            wr++;
        }
        r = word.end;
    }
    if (s != wr)
        wr--;
    *wr = '\0';
}

//task 18
// заполнение строки словами из сумки
void fillStrWords(char *s, BagOfWords bag, size_t start_copy_index) {
    char *wr = getEndOfString(s);
    if (*s != '\0') {
        *wr = ' ';
        wr++;
    }
    for (size_t i = start_copy_index; i < bag.size; i++) {
        wr = copyWord(wr, bag.words[i]);
        *wr = ' ';
        wr++;
    }
    *(wr - 1) = '\0';
}

// дополняет строку, содержащую меньшее количество слов, последними
// словами строки, в которой содержится большее количество слов.
void fillString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    if (_bag.size < _bag2.size)
        fillStrWords(s1, _bag2, _bag.size);
    else if (_bag.size > _bag2.size)
        fillStrWords(s2, _bag, _bag2.size);
}

// task 19
// возвращает 1, если символ есть в строке, иначе - нет
int isSymbolInString(char *s, char c) {
    while (*s != '\0') {
        if (*s == c)
            return 1;
        s++;
    }
    return 0;
}

// возвращает 1, если в данную строку входит каждая
// буква данного слова, иначе - 0
int isAllLettersFromWordInString(char *s, WordDescriptor w) {
    while (w.begin != w.end) {
        if (isalpha(*w.begin)) {
            if (!isSymbolInString(s, *w.begin))
                return 0;
        }
        w.begin++;
    }
    return 1;
}

