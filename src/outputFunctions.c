#include "../inc/uls.h"

static int max_len_file(char **files, int size) {
    int max = 0;
    int temp = 0;

    for (int i = 0; i < size; i++) {
        temp = mx_strlen(files[i]);
        if (temp > max)
            max = temp;
    }
    if (max % 8 == 0)
        max += 8;
    else
        max = 8 - (max % 8) + max;
    return max;
}

static void print_names(char **files, int maxlen, int wincol) {
    int rows;
    int cols = (wincol / maxlen) != 0 ? wincol / maxlen : 1;
    int num = 0;

    for (; files[num]; num++) {
    }
    if (maxlen * cols > wincol && cols != 1)
        cols--;
    if (num * maxlen > wincol) {
        rows = num / cols;
        if (rows == 0 || num % cols != 0)
            rows += 1;
 ////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
        //print_cols(files, rows, num, maxlen);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; i + j < num; j += rows) {
                mx_printstr(files[i + j]);
                if (files[i + j + 1] && (i + j + rows < num)) {
                    int count = 0;
                    int p;
                    p = maxlen - mx_strlen(files[i + j]);
                    if (p % 8 != 0)
                        count = (p / 8) + 1;
                    else
                        count = p / 8;
                    for (int i = 0; i < count; i++)
                        mx_printchar('\t');
                }
            }
            if (i != rows - 1)
                mx_printchar('\n');
        }
 ////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
    }
    else
        for (int i = 0; files[i]; i++) {
            mx_printstr(files[i]);
            if (files[i + 1]) {
                int count = 0;
                int p;
                p = maxlen - mx_strlen(files[i]);
                if (p % 8 != 0)
                    count = (p / 8) + 1;
                else
                    count = p / 8;
                for (int i = 0; i < count; i++)
                    mx_printchar('\t');
            }
        }
    mx_printchar('\n');
}

void output_by_cols(char **files, int size) {
    int maxlen;
    struct winsize win;

    if (!files)
        return;
    maxlen = max_len_file(files, size);
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
    if (isatty(1))
        print_names(files, maxlen, win.ws_col);
    else
        print_names(files, maxlen, 80);
}

