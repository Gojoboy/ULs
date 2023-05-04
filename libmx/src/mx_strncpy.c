#include "../inc/libmx.h"

char *mx_strncpy(char *dst, const char *src, int len) {
    int i;
    for (i = 0; i < len && src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    for (int j = i; j < len; j++) {
        dst[j] = '\0';
    }
    return dst;
}

