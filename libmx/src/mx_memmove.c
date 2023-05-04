#include "../inc/libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
    unsigned char *temp_src = (unsigned char*)src;
    unsigned char *temp_dst = (unsigned char*)dst;
    
    unsigned char *temp = (unsigned char*)malloc(len);
    
    for (int i = 0; i < (int)len; i++)
        temp[i] = temp_src[i];
    for (int i = 0; i < (int)len; i++)
        temp_dst[i] = temp[i];
    free(temp);
    return dst;
}

