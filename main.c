# include "libs/data_structures/string_/tasks/tasks.c"
# include "libs/data_structures/string_/string_.h"
# include "stdio.h"
# include "stdlib.h"
# define ASSERT_STRING(expected, got) assertString(expected, got, \
__FILE__, __FUNCTION__, __LINE__)

void assertString(const char *expected, char *got,

                  char const *fileName, char const *funcName,
                  int line) {
    if (strcmp(expected, got) != 0) {
        fprintf(stderr, "File %s\n", fileName);
        fprintf(stderr, "%s - failed on line %d\n", funcName, line);
        fprintf(stderr, "Expected: \"%s\"\n", expected);
        fprintf(stderr, "Got: \"%s\"\n\n", got);
    } else
        fprintf(stderr, "%s - OK\n", funcName);
}

// Task 1

// нет пробелов
void test_removeNonLetters_onlyLetters(){
    char s[] = "hello\0";
    char exp[] = "hello\0";
    removeNonLetters(s);
    ASSERT_STRING(exp, s);
}

// один пробел
void test_removeNonLetters_oneSpace(){
    char s[] = "ab 1\0";
    char exp[] = "ab1\0";
    removeNonLetters(s);
    ASSERT_STRING(exp, s);
}

// много пробелов
void test_removeNonLetters_manySpaces(){
    char s[] = "ab 1c2 3 fe f 4h6 j\0";
    char exp[] = "ab1c23fef4h6j\0";
    removeNonLetters(s);
    ASSERT_STRING(exp, s);
}

// Task 2

// пустая строка
void test_removeAdjacentEqualLetters_emptyString() {
    char s[] = "\0";
    char exp[] = "\0";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(exp, s);
}

// один символ
void test_removeAdjacentEqualLetters_oneSymbol() {
    char s[] = "a\0";
    char exp[] = "a\0";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(exp, s);
}

// 2 одинаковых символа
void test_removeAdjacentEqualLetters_2SameSymbols() {
    char s[] = "aa\0";
    char exp[] = "a\0";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(exp, s);
}

// 3 одинаковых символа
void test_removeAdjacentEqualLetters_3SameSymbols() {
    char s[] = "aaa\0";
    char exp[] = "a\0";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(exp, s);
}

// 2 пары одинаковых символов
void test_removeAdjacentEqualLetters_2PairsSameSymbols() {
    char s[] = "aabb\0";
    char exp[] = "ab\0";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(exp, s);
}

// разые символы и пробелы
void test_removeAdjacentEqualLetters_differentSymbolsAndSpaces() {
    char s[] = "aaa bb c\0";
    char exp[] = "a b c\0";
    removeAdjacentEqualLetters(s);
    ASSERT_STRING(exp, s);
}

void test() {
    test_removeNonLetters_onlyLetters();
    test_removeNonLetters_oneSpace();
    test_removeNonLetters_manySpaces();
    test_removeAdjacentEqualLetters_emptyString();
    test_removeAdjacentEqualLetters_oneSymbol();
    test_removeAdjacentEqualLetters_2SameSymbols();
    test_removeAdjacentEqualLetters_3SameSymbols();
    test_removeAdjacentEqualLetters_2PairsSameSymbols();
    test_removeAdjacentEqualLetters_differentSymbolsAndSpaces();
}

int main() {
    test();

    return 0;
}