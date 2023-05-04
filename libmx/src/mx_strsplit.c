#include "../inc/libmx.h"

static int strlen(const char *s) {
    int i;
    for(i = 0; s[i] != '\0'; i++) {

    }
    return i;
}

static int count_words(const char *str, char c) {
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != c && (i == 0 || str[i - 1] == c)) {
            result++;
        }
    }
    return result;
}

static char *strncpy(char *dst, const char *src, int len) {
    int i;
    for (i = 0; i < len && src[i] != '\0'; i++) {
        dst[i] = src[i];
    }
    for (int j = i; j < len; j++) {
        dst[j] = '\0';
    }
    return dst;
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

static char *strndup(const char *s1, size_t n) {
    if (s1 == NULL || n == 0)
        return NULL;
    else {
        int len = 0;

        if((int)n >= strlen(s1))
            len = strlen(s1);
        else
            len = (int)n;

        char *temp = strnew(len);
        if (temp == NULL)
            return NULL;
        return strncpy(temp, s1, len);
    }
}

char **mx_strsplit(const char *s, char c) {
    if (s == NULL)
        return NULL;
    
    int words = count_words(s, c);
    char **arr = (char**)malloc(sizeof(char*) * (words + 1));
 
    for (int j = 0; j < words; j++) {
        const char *temp = s;
        int len = 0;
        while (*s == c) {
            s++;
            temp++;
        }
        while (*s != c) {
            len++;
            s++;
        }
        if (len > 0) {
            arr[j] = strndup(temp, len);
        }
    }
    arr[words] = NULL;
    return arr;
}

