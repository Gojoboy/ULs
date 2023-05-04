#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    int result = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != c && (i == 0 || str[i - 1] == c)) {
            result++;
        }
    }
    return result;
}

