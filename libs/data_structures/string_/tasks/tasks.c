# include "../string_.h"
# include <ctype.h>
# include "stdio.h"

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
        if(*copy_s != *(copy_s + 1)) {
            *s = *copy_s;
            s++;
        }
        copy_s++;
    }
    *s = '\0';
}
