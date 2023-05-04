#include "../inc/libmx.h"

void *mx_memset(void *b, int c, size_t n) {
    if (b) {
        unsigned char *temp_mem = (unsigned char*)b;
        for (size_t i = 0; i < n; i++) {
            temp_mem[i] = (unsigned char)c;
        }
    }
    return b;
}

