#include "../inc/libmx.h"

static char *strnew(const int size) {
    char *str = NULL;
    
    if (size <= 0)
        return NULL;
    str = (char *)malloc((size + 1) * sizeof(char));
    
    if (str == NULL)
        return NULL;
    for (int i = 0; i < size; i++) {
        str[i] = '\0';
    }
    str[size] = '\0';
    return str;
}

char *mx_file_to_str(const char *file) {
    if (file == NULL)
        return NULL;
    int fd = open(file, O_RDONLY);
    if (fd < 0)
        return NULL;
        
    int len = 0;
    char c;
    while (read(fd, &c, 1) != 0)
        len++;

    close(fd);
    fd = open(file, O_RDONLY);

    char *tmp = strnew(len);
    read(fd, tmp, len);
    close(fd);
    return tmp;
}

