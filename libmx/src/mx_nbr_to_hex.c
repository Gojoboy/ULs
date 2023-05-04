#include "../inc/libmx.h"

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

static int size(unsigned long n) {
    if (n == 0)
        return 1;
    
    int count = 0;
    
    while (n != 0) {
        count++;
        n /= 16;
    }
    return count;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    char *result = strnew(size(nbr));
    int rem;
    int i = size(nbr) - 1;
    if (nbr == 0) {
        result[i] = '0';
        return result;
    }
    while (nbr != 0) {
        rem = nbr % 16;
        if (rem < 10) {
            result[i] = 48 + rem;
            i--;
        }
        else {
            result[i] = 87 + rem;
            i--;
        }
        nbr /= 16;
    }
    return result;
}

