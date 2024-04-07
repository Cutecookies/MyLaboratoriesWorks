# include <assert.h>
# include "libs/data_structures/string_/string_.h"
# include "stdio.h"
#include "math.h"
# include "stdlib.h"

void test_strlen_oneZeroElement() {
    char word[7] = {'H', 'e', 'l', 'l', 'o', '\0'};
    assert(strlen_(word) == 5);
}

void test_strlen_manyZeroElements() {
    char word[9] = {'H', 'e', 'l', 'l', 'o', '\0', '\0', '\0', '\0'};
    assert(strlen_(word) == 5);
}

// есть элемент
void test_ind_isElement() {
    char word[7] = {'H', 'e', 'l', 'l', 'o', '\0'};
    assert(find(word, word + 3, 'e') == word + 1);
}

// нет элемента
void test_ind_isNoElement() {
    char word[7] = {'H', 'e', 'l', 'l', 'o', '\0'};
    assert(find(word, word + 3, 'k') == word + 3);
}

// есть не пробельный символ
void test_findNonSpace_isNonSpace() {
    char word[7] = {' ', ' ', ' ', 'k', 'o', '\0'};
    assert(findNonSpace(word) == word + 3);
}

// нет не пробельного символа
void test_findNonSpace_noNonSpace() {
    char word[7] = {' ', ' ', ' ', '\0'};
    assert(findNonSpace(word) == word + 3);
}

// есть пробельный символ
void test_findSpace_isSpace() {
    char word[7] = {'g', 'h', ' ', 't', ' ', '\0'};
    assert(findSpace(word) == word + 2);
}

// нет пробельного символа
void test_findSpace_noSpace() {
    char word[7] = {'k', 'w', 'a', '\0'};
    assert(findSpace(word) == word + 3);
}

// есть не пробельный символ
void test_findNonSpaceReverse_isNonSpace() {
    char word[7] = {'j', ' ', ' ', 'l', ' ', '\0'};
    assert(findNonSpaceReverse(word + strlen_(word) - 1, word - 1) == word + 3);
}

// нет не пробельного символа
void test_findNonSpaceReverse_noNonSpace() {
    char word[7] = {' ', ' ', ' ', '\0'};
    assert(findNonSpaceReverse(word + strlen_(word) - 1, word - 1) == word - 1);
}

// есть пробельный символ
void test_findSpaceReverse_isNonSpace() {
    char word[7] = {'j', ' ', ' ', 'h', 'p', '\0'};
    assert(findSpaceReverse(word + strlen_(word) - 1, word - 1) == word + 2);
}

// нет пробельного символа
void test_findSpaceReverse_noNonSpace() {
    char word[7] = {'A', 'B', 'C', '\0'};
    assert(findSpaceReverse(word + strlen_(word) - 1, word - 1) == word - 1);
}

// lhs = rhs
void test_strcmp_equal() {
    char lhs[4] = {'A', 'B', 'C', '\0'};
    char rhs[4] = {'A', 'B', 'C', '\0'};
    assert(strcmp(lhs, rhs) == 0);
}

// lhs < rhs
void test_strcmp_less() {
    char lhs[4] = {'A', 'B', 'C', '\0'};
    char rhs[4] = {'A', 'B', 'D', '\0'};
    assert(strcmp(lhs, rhs) < 0);
}

// lhs > rhs
void test_strcmp_more() {
    char lhs[4] = {'A', 'B', 'D', '\0'};
    char rhs[4] = {'A', 'B', 'C', '\0'};
    assert(strcmp(lhs, rhs) > 0);
}

void test_copy() {
    char lhs[4] = {'A', 'B', 'D', '\0'};
    char rhs[4] = {'a', 'b', 'c', '\0'};
    assert(copy(lhs, lhs + 2, rhs) == rhs + 2);
    assert(*rhs == 'A');
    assert(*rhs + 1 == 'B');
}

int isOdd(int a) {
    return a % 2 != 0? 1: 0;
}

void test_copyIf() {
    char lhs[8] = {'1', '2', '3', '4', '5', '6', '\0'};
    char rhs[6] = {' ', ' ', ' ', ' ', ' ', '\0'};
    assert(copyIf(lhs, lhs + 3, rhs, isOdd) == rhs + 2);
    assert(rhs[0] == '1');
    assert(rhs[1] == '3');
    assert(rhs[2] == ' ');
}

void test_copyIfReverse() {
    char lhs[8] = {'1', '2', '3', '4', '5', '6', '\0'};
    char rhs[6] = {' ', ' ', ' ', ' ', ' ', '\0'};
    assert(copyIfReverse(lhs + 4, lhs, rhs, isOdd) == rhs + 2);
    assert(rhs[0] == '5');
    assert(rhs[1] == '3');
    assert(rhs[2] == ' ');
}

void test() {
    test_strlen_oneZeroElement();
    test_strlen_manyZeroElements();
    test_ind_isElement();
    test_ind_isNoElement();
    test_findNonSpace_isNonSpace();
    test_findNonSpace_noNonSpace();
    test_findSpace_isSpace();
    test_findSpace_noSpace();
    test_findNonSpaceReverse_isNonSpace();
    test_findNonSpaceReverse_noNonSpace();
    test_findSpaceReverse_isNonSpace();
    test_findSpaceReverse_noNonSpace();
    test_strcmp_equal();
    test_strcmp_less();
    test_strcmp_more();
    test_copy();
    test_copyIf();
    test_copyIfReverse();
}

int main() {
    test();

    return 0;
}