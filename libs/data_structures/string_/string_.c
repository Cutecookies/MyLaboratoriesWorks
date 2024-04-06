# include "string_.h"
# include "malloc.h"
# include <stdio.h>
# include "assert.h"
# include "stdbool.h"

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}