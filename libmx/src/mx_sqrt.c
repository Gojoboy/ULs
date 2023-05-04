#include "../inc/libmx.h"

int mx_sqrt(int x) {
    int i = 1;
    
    if (x == 0
        || x == 1)
        return x;
    while (i * i <= x)
        i++;
    
    i--;
    
    if (i * i == x)
        return i;
    else
        return 0;
}

