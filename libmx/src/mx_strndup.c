#include "../inc/libmx.h"

static int strlen(const char *s) {
    int i;
    for(i = 0; s[i] != '\0'; i++) {

    }
    return i;
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

char *mx_strndup(const char *s1, size_t n) {
    size_t len = strlen(s1);
        
    if (len > n)
        len = n;
    char *temp = strnew(len);
    if (temp == NULL)
        return NULL;
    
    for (size_t i = 0; i < len; i++) {
        temp[i] = s1[i];
    }
    temp[len] = '\0';
    return temp;
}

