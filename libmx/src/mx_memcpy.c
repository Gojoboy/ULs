#include "../inc/libmx.h"

void *mx_memcpy(void *restrict dst, const void *restrict src, size_t len) {
    if (src) {
        for (size_t i = 0; i < len; i++) {
            ((unsigned char*)dst)[i] = ((unsigned char*)src)[i];
        }
    }
    return dst;
}

