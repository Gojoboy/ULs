#include "../inc/libmx.h"

static int strlen(const char *s) {
    int i;
    for(i = 0; s[i] != '\0'; i++) {

    }
    return i;
}

static void swap(char **first, char **second) {
    char *temp = *first;
    *first = *second;
    *second = temp;
}

int mx_quicksort(char **arr, int left, int right) {
    int swaps = 0;
    int i = left;
    int j = right;
    int pivot = (i + j) / 2;

    if (i >= j)
        return 0;
    if (arr == NULL)
        return -1;

    while (i < j) {
        while (strlen(arr[i]) < strlen(arr[pivot])) {
            i++;
        }
        while (j > left
               && strlen(arr[j]) >= strlen(arr[pivot])) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
            swaps++;
        }
    }

    if (i != pivot) {
        swap(&arr[i], &arr[pivot]);
        swaps++;
    }
    swaps += mx_quicksort(arr, left, i - 1);
    swaps += mx_quicksort(arr, i + 1, right);

    return swaps;
}

