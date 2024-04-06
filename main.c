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

void test() {
    test_strlen_oneZeroElement();
    test_strlen_manyZeroElements();
}

int main() {
    test();

    return 0;
}