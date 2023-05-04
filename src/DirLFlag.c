#include "../inc/uls.h"

void l_flag_this_dir(DIR *dir, struct dirent *entry, char *path) {
    if ((dir = opendir(path)) == NULL) {
        perror("");
        exit(EXIT_FAILURE);
    }
    else {
        int size = 0;
        while ((entry = readdir(dir)) != NULL)
        {
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
 ////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
        //count_total(dir, entry, path);
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

            int total = 0;
            char *fullPath = mx_strjoin(path, "/");
            for (int i = 0; i < size; i++) {
                struct stat filestat;
                stat(mx_strjoin(fullPath, files[i]), &filestat);
                total += filestat.st_blocks;
            }
            //clean_array(files, size);
            for (int i = 0; i < size; i++) {
                free(files[i]);
            }
            free(files);
            mx_printstr("total ");
            mx_printint(total); // total / 2
            mx_printchar('\n');
        }
        //free(entry);
        //closedir(dir);
 ////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
        char *fullPath = mx_strjoin(path, "/");
        for (int i = 0; i < size; i++) {
            struct stat filestat;
            stat(mx_strjoin(fullPath, files[i]), &filestat);
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
        //clean_array(files, size);
        for (int i = 0; i < size; i++) {
            free(files[i]);
        }
        free(files);
    }
    free(entry);
    closedir(dir);
}

