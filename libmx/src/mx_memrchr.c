#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    unsigned char *ptr = (unsigned char*)s + (int)n - 1;
    
    while (n > 0) {
        if (*ptr == (unsigned char)c)
            return ptr;
        ptr--;
        n--;
    }
    return NULL;
}

