#include "../inc/uls.h"

int check_empty(DIR *dir, struct dirent *entry, char *path) {
    if ((dir = opendir(path)) == NULL) {
        perror("");
        return 1;
    }
    else {
        int size = 0;
        while ((entry = readdir(dir)) != NULL) {
            size++;
        }
        if (size == 2)
            return 0;
        else
            return 1;
    }
}

