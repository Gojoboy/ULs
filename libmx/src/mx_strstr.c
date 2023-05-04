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

static char *strchr(const char *s, char c) {
    if (s == NULL) {
        return NULL;
    }
    while (*s != '\0') {
        if (*s == c){
            return (char*)s;
        }
        s++;
        if (c == '\0'
            && *s == c) {
            return (char*)s;
        }
    }
    return NULL;
}

char *mx_strstr(const char *haystack, const char *needle) {
    const char *temp = haystack;
    int len = strlen(needle);
    temp = strchr(temp, *needle);

    if (temp == NULL)
        return NULL;
  
    while (temp != 0) {
        if (strncmp(temp, needle, len) == 0)
            return (char*)temp;
        temp++;
        temp = strchr(temp, *needle);
    }
    return NULL;
}

