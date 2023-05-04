#include "../libmx/inc/libmx.h"
#include "../inc/uls.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    if (argc == 1) {
        this_dir(dir, entry, ".");
        exit(EXIT_SUCCESS);
    }
    if (argc > 1) {
        if (argv[1][0] == '-') {
            if (mx_strcmp("-l", argv[1]) == 0) {
                if (argc >= 3) {
                    l_flag_more_dir(argc, argv);
                }
                else {
                    l_flag_this_dir(dir, entry, ".");
                }

                exit(EXIT_SUCCESS);
            }
            else {
                mx_printstr("uls: illegal option -- ");
                char **phrase = mx_strsplit(argv[1], '-');
                mx_printstr(phrase[0]);
                mx_printchar('\n');
                mx_printstr("usage: uls [-l] [file ...]\n");
                exit(EXIT_FAILURE);
            }
        }
        else {
 ////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
            //more_dir(argc, argv);
            DIR *dir = NULL;
            struct dirent *entry = NULL;
            bool consist;
            char **directories = NULL;
            char **files = NULL;
            int countDir = 0;
            int countFiles = 0;
            int temp = 0;

            for (int i = 1; i < argc; i++) {
                if (opendir(argv[i]) != NULL)
                    countDir++;
                else
                    countFiles++;
            }
            temp = countFiles;

            directories = (char **)malloc(countDir * sizeof(char *));
            files = (char **)malloc(countFiles * sizeof(char *));

            for (int i = 0; i < countDir; i++)
                directories[i] = mx_strnew(25);
            for (int i = 0; i < countFiles; i++)
                files[i] = mx_strnew(25);

            int a = 0;
            int b = 0;
            for (int i = 1; i < argc; i++) {
                if (opendir(argv[i]) != NULL) {
                    directories[a] = mx_strdup(argv[i]);
                    a++;
                }
                else {
                    if (mx_get_char_index(argv[i], '/') != -1) {
                        char **name = mx_strsplit(argv[i], '/');

                        dir = opendir(name[0]);
                        while ((entry = readdir(dir)) != NULL) {
                            if (mx_strcmp(name[1], entry->d_name) == 0) {
                                consist = true;
                                break;
                            }
                            else
                                consist = false;
                        }
                        closedir(dir);
                        if (!consist) {
                            mx_printstr("uls: ");
                            mx_printstr(argv[i]);
                            mx_printstr(": No such file or directory\n");
                            countFiles--;
                            continue;
                        }
                        files[b] = mx_strdup(argv[i]);
                        b++;
                    }
                    else {
                        dir = opendir(".");
                        while ((entry = readdir(dir)) != NULL) {
                            if (mx_strcmp(argv[i], entry->d_name) == 0) {
                                consist = true;
                                break;
                            }
                            else
                                consist = false;
                        }
                        closedir(dir);
                        if (!consist) {
                            mx_printstr("uls: ");
                            mx_printstr(argv[i]);
                            mx_printstr(": No such file or directory\n");
                            countFiles--;
                            continue;
                        }
                        files[b] = mx_strdup(argv[i]);
                        b++;
                    }
                }
            }
            mx_bubble_sort(directories, countDir);
            mx_bubble_sort(files, countFiles);

            for (int i = 0; i < countFiles; i++) {
                mx_printstr(files[i]);
                mx_printchar('\t');
            }
            if (countFiles > 0 && countDir == 0)
                mx_printchar('\n');
            else if (countFiles != 0 && countDir != 0)
                mx_printstr("\n\n");

            for (int i = 0; i < countDir; i++) {
                if (check_empty(dir, entry, directories[i]) == 0) {
                    mx_printstr(directories[i]);
                    mx_printstr(":\t# empty directory\n");
                    if (i != countDir - 1)
                        mx_printchar('\n');
                    continue;
                }
                if (countDir == 1 && temp == 0) {
                    this_dir(dir, entry, directories[i]);
                    break;
                }
                if (countDir == 1 && temp > 0) {
                    mx_printstr(directories[i]);
                    mx_printstr(":\n");
                    this_dir(dir, entry, directories[i]);
                    break;
                }
                mx_printstr(directories[i]);
                mx_printstr(":\n");
                this_dir(dir, entry, directories[i]);
                if (i != countDir - 1)
                    mx_printchar('\n');
            }
            //clean_array(directories, countDir);
            for (int i = 0; i < countDir; i++) {
                free(directories[i]);
            }
            free(directories);
            //clean_array(files, temp);
            for (int i = 0; i < temp; i++) {
                free(files[i]);
            }
            free(files);
 ////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
            exit(EXIT_SUCCESS);
        }
    }
    exit(EXIT_SUCCESS);
}

