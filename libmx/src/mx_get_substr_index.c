#include "../inc/libmx.h"

static int strlen(const char *s) {
    int i;
    for(i = 0; s[i] != '\0'; i++) {

    }
    return i;
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

int mx_get_substr_index(const char *str, const char *sub) {
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

