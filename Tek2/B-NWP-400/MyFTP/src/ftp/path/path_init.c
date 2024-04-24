/*
** EPITECH PROJECT, 2024
** path_init.c
** File description:
** path_init.c
*/

#include "ftp/path.h"
#include "utils/parsing.h"

#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

bool path_init(path_t *self, const char *root)
{
    struct stat sb;

    if (stat(root, &sb) != 0 || !S_ISDIR(sb.st_mode))
        return false;
    self->root = strdup(root);
    self->path = strdup(root);
    if (self->root == NULL || self->path == NULL) {
        free(self->root);
        free(self->path);
        return false;
    }
    remove_trailing_slashes(self->root);
    remove_trailing_slashes(self->path);
    return true;
}
