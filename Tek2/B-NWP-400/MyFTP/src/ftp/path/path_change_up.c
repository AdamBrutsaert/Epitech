/*
** EPITECH PROJECT, 2024
** path_change_up.c
** File description:
** path_change_up.c
*/

#include "ftp/path.h"

#include <string.h>

void path_change_up(path_t *self)
{
    size_t length = strlen(self->path);

    if (strcmp(self->root, self->path) == 0)
        return;
    for (; length > 1 && self->path[length - 1] != '/'; length--)
        self->path[length - 1] = '\0';
    if (length > 1 && self->path[length - 1] == '/')
        self->path[length - 1] = '\0';
}
