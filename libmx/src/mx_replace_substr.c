#include "../inc/libmx.h"

static int strlen(const char *s) {
    int i;
    for(i = 0; s[i] != '\0'; i++) {

    }
    return i;
}

static int count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL)
        return -1;
    int M = strlen(sub);
    int N = strlen(str);
    int res = 0;

    for (int i = 0; i <= N - M; i++) {
        int j;
        for (j = 0; j < M; j++) {
            if (str[i+j] != sub[j])
                break;
        }
        if (j == M) {
            res++;
        }
    }
    return res;
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

static int strncmp(const char *s1, const char *s2, int size) {
    int res = 0;
    int i = 0;
    while (size) {
        if (s1[i] == '\0' && s2[i] != '\0') {
            return -(int)s2[i];
        }
        else if (s2[i] == '\0' && s1[i] != '\0') {
            return (int)s1[i];
        }
        if (s1[i] != s2[i]) {
            res = (int)s1[i] - (int)s2[i];
            return res;
        }
    size--;
    i++;
    }
    return res;
}

static char *strcpy(char *dst, const char *src) {
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

static void strdel(char **str) {
    if (str != NULL) {
        free(*str);
        *str = NULL;
    }
    else
        return;
}

static int get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL)
        return -2;

    int index = 0;
    int sublen = strlen(sub);

    while (*str) {
        if (strncmp(str, sub, sublen) == 0) {
            return index;
        }
        str++;
        index++;
    }

    return -1;
}

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL
        || strlen(str) <= strlen(sub) || strlen(str) <= strlen(replace))
        return NULL;
    
    int size = strlen(str) - (count_substr(str, sub) * strlen(sub)) + (count_substr(str, sub) * strlen(replace));
    char *result = strnew(size);
    
    char *strstr = strnew(strlen(str));
    strcpy(strstr, str);
    
    for (int i = 0; i < size; i++) {
        int index = get_substr_index(strstr, sub);
        if (i != index)
            result[i] = str[i];
        else {
            for (int j = 0; j < strlen(replace); j++) {
                strstr[j + index] = replace[j];
                result[j + index] = replace[j];
            }
            i += strlen(replace) - 1;
        }
    }
    strdel(&strstr);
    return result;
}

