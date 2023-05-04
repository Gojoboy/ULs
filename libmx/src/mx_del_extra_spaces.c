#include "../inc/libmx.h"

static int strlen(const char *s) {
    int i;
    for(i = 0; s[i] != '\0'; i++) {

    }
    return i;
}

static bool isspace(char c) {
    if ((c >= 9 && c <= 13) || c == 32) {
        return true;
    }
    else {
        return false;
    }
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

static void strdel(char **str) {
    if (str != NULL) {
        free(*str);
        *str = NULL;
    }
    else
        return;
}

static char *strtrim(const char *str) {
    if (str == NULL)
        return NULL;
    else {
        char *temp = strncpy(strnew(strlen(str)), str, strlen(str));
        char *start = &temp[0];
        
        while (isspace(*temp))
            temp++;
        int size = strlen(temp);
        while (isspace(temp[size - 1]))
            size--;
        temp[size] = '\0';
        
        char *text = strncpy(strnew(strlen(temp)), temp, strlen(temp));
        strdel(&start);
        return text;
    }
}

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL)
        return NULL;
    int j = 0;
    char *temp = strtrim(str);
    char *result = strnew(strlen(temp));
    
    for (int i = 0; i < strlen(temp); i++)
        if (!isspace(temp[i])) {
            result[j] = temp[i];
            j++;
        }
        else {
            if (!isspace(temp[i + 1])) {
                result[j] = ' ';
                j++;
            }
        }
    result[j] = '\0';
    strdel(&temp);
    return result;
}

