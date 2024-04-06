# include "string_.h"
# include "malloc.h"
# include <stdio.h>
# include "assert.h"
# include "stdbool.h"
# include <ctype.h>

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char* find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char* findNonSpace(char *begin) {
    while(*begin != '\0') {
        if (!isspace(*begin)){
            return begin;}
        begin++;
    }
    return begin;
}

char* findSpace(char *begin) {
    while(*begin != '\0') {
        if (isspace(*begin))
            return begin;
        begin++;
    }
    return begin;
}

char* findNonSpaceReverse(char *rbegin, const char *rend) {
    while(*rbegin != *rend) {
        if (!isspace(*rbegin)){
            return rbegin;}
        rbegin--;
    }
    return rbegin;
}

char* findSpaceReverse(char *rbegin, const char *rend) {
    while(*rbegin != *rend) {
        if (isspace(*rbegin)){
            return rbegin;}
        rbegin--;
    }
    return rbegin;
}