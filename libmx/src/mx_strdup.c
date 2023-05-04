#include "../inc/libmx.h"

static int strlen(const char *s) {
    int i;
    for(i = 0; s[i] != '\0'; i++) {

    }
    return i;
}

static char *strcpy(char *dst, const char *src) {
    char *ptr = dst;
    
    if (dst == NULL) {
        return NULL;
    }
    while (*src != '\0')
    {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    
    return ptr;
}

static char *strnew(const int size) {
    if (size <= 0)
        return NULL;
    char *str = (char *)malloc(size + 1);
    
    if (str == NULL)
        return NULL;
    for (int i = 0; i < size; i++) {
        str[i] = '\0';
    }
    str[size] = '\0';
    return str;
}

char *mx_strdup(const char *str) {
    char *output = strnew(strlen(str));
    strcpy(output, str);
    return output;
}

