#include "../inc/libmx.h"

static int strlen(const char *s) {
    int i;
    for(i = 0; s[i] != '\0'; i++) {

    }
    return i;
}

int mx_count_substr(const char *str, const char *sub) {
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

