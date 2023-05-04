#include "../inc/uls.h"

void l_flag_more_dir(int num, char **argv) {
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    bool consist;
    char **directories = NULL;
    char **files = NULL;
    int countDir = 0;
    int countFiles = 0;
    int temp = 0;

    for (int i = 2; i < num; i++) {
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
    int c = 0;
    for (int i = 2; i < num; i++) {
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
                if (mx_strcmp(argv[i], "-l") == 0 && b == 0 && a == 0) {
                    countFiles--;
                    c++;
                    continue;
                }
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
                if (mx_strcmp(argv[i], "-l") == 0 && b == 0 && a == 0) {
                    countFiles--;
                    c++;
                    continue;
                }
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

    if (countDir == 0) {
        if (c == temp) {
            l_flag_this_dir(dir, entry, ".");
            exit(EXIT_SUCCESS);
        }
    }

    for (int i = 0; i < countFiles; i++) {
        struct stat filestat;
        stat(files[i], &filestat);
        char *temp = ctime(&filestat.st_ctime);
        if (temp[mx_strlen(temp) - 1] == '\n')
            temp[mx_strlen(temp) - 1] = '\0';
        char **arr = mx_strsplit(temp, ' ');
        struct passwd *pw = getpwuid(filestat.st_uid);
        struct group *gr = getgrgid(filestat.st_gid);

        //show_permission(filestat);
        mx_printstr((S_ISDIR(filestat.st_mode)) ? "d" : "-");
        mx_printstr((filestat.st_mode & S_IRUSR) ? "r" : "-");
        mx_printstr((filestat.st_mode & S_IWUSR) ? "w" : "-");
        mx_printstr((filestat.st_mode & S_IXUSR) ? "x" : "-");
        mx_printstr((filestat.st_mode & S_IRGRP) ? "r" : "-");
        mx_printstr((filestat.st_mode & S_IWGRP) ? "w" : "-");
        mx_printstr((filestat.st_mode & S_IXGRP) ? "x" : "-");
        mx_printstr((filestat.st_mode & S_IROTH) ? "r" : "-");
        mx_printstr((filestat.st_mode & S_IWOTH) ? "w" : "-");
        mx_printstr((filestat.st_mode & S_IXOTH) ? "x" : "-");
        mx_printchar(' ');
        mx_printint(filestat.st_nlink);
        mx_printchar(' ');
        mx_printstr(pw->pw_name);
        mx_printchar(' ');
        mx_printstr(gr->gr_name);
        mx_printchar(' ');
        mx_printint(filestat.st_size);
        mx_printchar(' ');
        mx_printstr(arr[1]);
        mx_printchar(' ');
        mx_printstr(arr[2]);
        mx_printchar(' ');
        int j = 0;
        for (int i = 0;; i++) {
            if (arr[3][i] == ':')
                j++;
            if (j == 2)
                break;
            mx_printchar(arr[3][i]);
        }
        mx_printchar(' ');
        mx_printstr(files[i]);
        mx_printchar('\n');
    }

    if (countFiles != 0 && countDir != 0)
        mx_printchar('\n');

    for (int i = 0; i < countDir; i++) {
        if (check_empty(dir, entry, directories[i]) == 0) {
            mx_printstr(directories[i]);
            mx_printstr(":\t# empty directory\n");
            if (i != countDir - 1)
                mx_printchar('\n');
            continue;
        }
        if (countDir == 1 && countFiles == 0) {
            l_flag_this_dir(dir, entry, directories[i]);
            break;
        }
        if (countDir == 1 && temp > 0) {
            mx_printstr(directories[i]);
            mx_printstr(":\n");
            l_flag_this_dir(dir, entry, directories[i]);
            break;
        }
        mx_printstr(directories[i]);
        mx_printstr(":\n");
        l_flag_this_dir(dir, entry, directories[i]);

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
}

