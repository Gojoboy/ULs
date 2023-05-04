#include "../inc/libmx.h"

char *mx_strcpy(char *dst, const char *src) {
    char *ptr = dst;
    
    if (dst == NULL)
        return NULL;
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    
    return ptr;
}

