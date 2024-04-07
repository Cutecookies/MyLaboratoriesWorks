# include "string_.h"
# include <stdio.h>
# include "assert.h"
# include <ctype.h>
# include <memory.h>

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0')
        end++;
    return end - begin;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;
    return begin;
}

char *findNonSpace(char *begin) {
    while (*begin != '\0') {
        if (!isspace(*begin)) {
            return begin;
        }
        begin++;
    }
    return begin;
}

char *findSpace(char *begin) {
    while (*begin != '\0') {
        if (isspace(*begin))
            return begin;
        begin++;
    }
    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (*rbegin != *rend) {
        if (!isspace(*rbegin)) {
            return rbegin;
        }
        rbegin--;
    }
    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (*rbegin != *rend) {
        if (isspace(*rbegin)) {
            return rbegin;
        }
        rbegin--;
    }
    return rbegin;
}

int strcmp(const char *lhs, const char *rhs) {
    while (*lhs == *rhs && *lhs != '\0') {
        lhs++;
        rhs++;
    }
    if (*lhs == '\0' && *rhs == '\0')
        return 0;
    if (*lhs == '\0')
        lhs--;
    if (*rhs == '\0')
        rhs--;
    return *lhs < *rhs ? -1 : 1;
}

char *copy(const char *beginSource, const char *endSource,
           char *beginDestination) {
    size_t length = endSource - beginSource;
    memcpy(beginDestination, beginSource, length);
    return beginDestination + length;
}

char* copyIf(char *beginSource, const char *endSource,
             char *beginDestination, int (*f)(int)) {
    while (*beginSource != *endSource) {
        if(f(*beginSource)) {
            *beginDestination = *beginSource;
            beginDestination++;
        }
        beginSource++;
    }
    return beginDestination;
}

char* copyIfReverse(char *rbeginSource, const char *rendSource,
                    char *beginDestination, int (*f)(int)) {
    while (*rbeginSource != *rendSource) {
        if(f(*rbeginSource)) {
            *beginDestination = *rbeginSource;
            beginDestination++;
        }
        rbeginSource--;
    }
    return beginDestination;
}