#include "../inc/libmx.h"

static int strcmp(const char *s1, const char *s2) {
    while (*s1) {
        if (*s1 != *s2) {
            break;
        }
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int first = 0;
    int last = size - 1;
    
    while (first <= last) {
        (*count)++;
        int m = (first + last) / 2;
        if (strcmp(arr[m], s) == 0)
            return m;
        if (strcmp(arr[m], s) < 0)
            first = m + 1;
        else
            last = m - 1;
    }
    if (first > last) {
        *count = 0;
        return -1;
    }
    return -1;
}

