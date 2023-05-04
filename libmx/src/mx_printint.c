#include "../inc/libmx.h"

static void printchar(char c) {
    write(1, &c, 1);
}

void mx_printint(int n) {
    int integers[25];
    int size = 0;
    int current = n;
    
    if (n == 0)
        printchar(48);
    while (current != 0) {
        int digit = current % 10;
        if (digit < 0)
            digit *= -1;
        integers[size] = digit + 48;
        current /= 10;
        size++;
    }
    if (n < 0)
        printchar(45);
    for(int i = size - 1; i >= 0; i--)
        printchar(integers[i]);
}

