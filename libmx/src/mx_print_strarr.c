#include "../inc/libmx.h"

static int strlen(const char *s) {
    int i;
    for(i = 0; s[i] != '\0'; i++) {

    }
    return i;
}

static void printstr(const char *s) {
    write(1, s, strlen(s));
} 


static void printchar(char c) {
    write(1, &c, 1);
}

void mx_print_strarr(char **arr, const char *delim) {
    if (arr != NULL && delim != NULL) {
        for (int i = 0; arr[i] != NULL; i++) {
            printstr(arr[i]);
            if (arr[i + 1] != NULL)
                printstr(delim);
        }
        printchar('\n');
    }
}

