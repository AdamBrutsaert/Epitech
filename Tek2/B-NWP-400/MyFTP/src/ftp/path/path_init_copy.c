/*
** EPITECH PROJECT, 2024
** path_init_copy.c
** File description:
** path_init_copy.c
*/

#include "ftp/path.h"

#include <string.h>
#include <stdlib.h>

bool path_init_copy(path_t *self, const path_t *other)
{
    self->path = strdup(other->path);
    self->root = strdup(other->root);
    if (self->root == NULL || self->path == NULL) {
        free(self->root);
        free(self->path);
        return false;
    }
    return true;
}
