#include "../inc/libmx.h"

static int memcmp(const void *s1, const void *s2, size_t n) {
    if (!n)
        return 0;
    
    while (--n && *(unsigned char*)s1 == *(unsigned char*)s2) {
        s1 = (unsigned char*)s1 + 1;
        s2 = (unsigned char*)s2 + 1;
    }
    return *((unsigned char*)s1) - *((unsigned char*)s2);
}

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    unsigned char *temp_big = NULL;
    unsigned char *temp_little = NULL;

    if (big_len >= little_len && big_len > 0 && little_len > 0) {
        temp_big = (unsigned char *)big;
        temp_little = (unsigned char *)little;
        while (*temp_big) {
            if (memcmp(temp_big, temp_little, little_len) == 0)
                return temp_big;
            temp_big++;
        }
    }
    return NULL;
}

