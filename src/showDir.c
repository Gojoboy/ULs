#include "../inc/uls.h"

void this_dir(DIR *dir, struct dirent *entry, char *path) {
    if ((dir = opendir(path)) == NULL) {
        perror("");
        exit(EXIT_FAILURE);
    }
    else {
        int size = 0;
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] == '.')
                continue;
            size++;
        }
        closedir(dir);
        dir = opendir(path);
        char **files = (char **)malloc(size * sizeof(char *));

        for (int i = 0; i < size; i++)
            files[i] = mx_strnew(25);

        int k = 0;
        while ((entry = readdir(dir)) != NULL) {
            if (entry->d_name[0] == '.')
                continue;
            files[k] = mx_strdup(entry->d_name);
            k++;
        }
        mx_bubble_sort(files, size);

        if (isatty(STDOUT_FILENO)) {
            output_by_cols(files, size);
        }
        else {
            for (int i = 0; i < size; i++) {
                mx_printstr(files[i]);
                if (i != size - 1)
                    mx_printchar('\n');
            }
        }
        for (int i = 0; i < size; i++) {
            free(files[i]);
        }
        free(files);
    }

    free(entry);
    closedir(dir);
}

