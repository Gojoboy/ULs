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
    char *str = NULL;
    
    if (size <= 0)
        return NULL;
    str = (char *)malloc((size + 1) * sizeof(char));
    
    if (str == NULL)
        return NULL;
    for (int i = 0; i < size; i++) {
        str[i] = '\0';
    }
    str[size] = '\0';
    return str;
}

static char *strcat(char *s1, const char *s2) {
    char *end = s1 + strlen(s1);
    
    while (*s2 != '\0') {
        *end = *s2;
        end++;
        s2++;
    }
    *end = '\0';
    return s1;
}

static char *strdup(const char *str) {
    char *output = strnew(strlen(str));
    strcpy(output, str);
    return output;
}

char *mx_strjoin(char const *s1, char const *s2) {
    if (s1 == NULL && s2 == NULL)
        return NULL;
    else if (s1 == NULL && s2 != NULL) {
        char *joined = strdup(s2);
        return joined;
    }
    else if (s1 != NULL && s2 == NULL) {
        char *joined = strdup(s1);
        return joined;
    }
    else {
        char *joined = strnew(strlen(s1) + strlen(s2));
        joined = strcat(joined, s1);
        joined = strcat(joined, s2);
        return joined;
    }
}

