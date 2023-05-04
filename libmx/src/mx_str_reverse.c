#include "../inc/libmx.h"

static int strlen(const char *s) {
    int i;
    for(i = 0; s[i] != '\0'; i++) {

    }
    return i;
}

static void swap_char(char *s1, char *s2) {
    char current = *s1;

    *s1 = *s2;
    *s2 = current;
}

void mx_str_reverse(char *s) {
    for (int i = 0; i < strlen(s) / 2; i++) {
        if (strlen(s) % 2 != 0
            && i == strlen(s) / 2 + 1)
            break;
        swap_char(&s[i], &s[strlen(s) - 1 - i]);
    }
}

