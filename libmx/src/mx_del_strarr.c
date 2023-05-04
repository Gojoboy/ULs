#include "../inc/libmx.h"

static void strdel(char **str) {
    if (str != NULL) {
        free(*str);
        *str = NULL;
    }
    else
        return;
}

void mx_del_strarr(char ***arr) {
    int i = 0;
    while ((*arr)[i] != NULL) {
        strdel(&(*arr)[i]);
        i++;
    }
    free(*arr);
    *arr = NULL;
}

