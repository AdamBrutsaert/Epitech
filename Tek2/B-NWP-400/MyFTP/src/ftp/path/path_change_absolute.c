/*
** EPITECH PROJECT, 2024
** path_change_absolute.c
** File description:
** path_change_absolute.c
*/

#include "ftp/path.h"
#include "utils/parsing.h"

#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

bool path_change_absolute(path_t *self, const char *path)
{
    struct stat sb;
    char *copy;

    if (strncmp(path, self->root, strlen(self->root)) != 0)
        return false;
    if (stat(path, &sb) != 0 || !S_ISDIR(sb.st_mode))
        return false;
    copy = strdup(path);
    if (copy == NULL)
        return false;
    free(self->path);
    self->path = remove_trailing_slashes(copy);
    return true;
}
