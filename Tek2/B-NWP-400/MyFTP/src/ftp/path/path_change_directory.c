/*
** EPITECH PROJECT, 2024
** path_change_directory.c
** File description:
** path_change_directory.c
*/

#include "ftp/path.h"
#include "utils/parsing.h"

#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

bool path_change_directory(path_t *self, const char *directory)
{
    char *path;
    struct stat sb;

    path = calloc(strlen(self->path) + strlen(directory) + 2, sizeof(char));
    strcat(path, self->path);
    strcat(path, "/");
    strcat(path, directory);
    remove_trailing_slashes(path);
    if (stat(path, &sb) != 0 || !S_ISDIR(sb.st_mode)) {
        free(path);
        return false;
    }
    free(self->path);
    self->path = path;
    return true;
}
