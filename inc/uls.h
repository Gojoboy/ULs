#pragma once

#include "../libmx/inc/libmx.h"

#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int check_empty(DIR *dir, struct dirent *entry, char *path);
void this_dir(DIR *dir, struct dirent *entry, char *path);
void l_flag_this_dir(DIR *dir, struct dirent *entry, char *path);
void l_flag_more_dir(int num, char **argv);
void output_by_cols(char **files, int size);

