#include "../inc/libmx.h"

char *mx_itoa(int number) {
    int count = 0;
    int num = number;
    int temp = number;
    if (number == 0) {
        char *result = (char*)malloc((count + 2)*sizeof(char));
        for (int i = count; i <= count; i++)
            result[i] = num + '0';
        result[count + 1] = '\0';
        return result;
    }
    while(temp) {
        temp /= 10;
        count++;
    }
    if (number > 0) {
        char *result = (char *)malloc((count + 1) * sizeof(char));
        for (int i = count - 1; i >= 0; i--) {
            result[i] = num % 10 + '0';
            num /= 10;
        }
        result[count] = '\0';
        return result;
    }
    else {
        char *result = (char *)malloc((count + 2) * sizeof(char));
        for (int i = count; i >= 0; i--) {
            if (i == 0) {
                result[i] = '-';
                break;
            }
            temp = num % 10;
            if (temp < 0)
                temp *= -1;
            result[i] = temp + '0';
            num /= 10;
        }
        result[count + 1] = '\0';
        return result;
    }
}

