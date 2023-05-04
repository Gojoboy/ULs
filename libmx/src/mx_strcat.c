#include "../inc/libmx.h"

static int strlen(const char *s) {
    int i;
    for(i = 0; s[i] != '\0'; i++) {

    }
    return i;
}

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    char *end = s1 + strlen(s1);
    
    while (*s2 != '\0') {
        *end = *s2;
        end++;
        s2++;
    }
    *end = '\0';
    return s1;
}

