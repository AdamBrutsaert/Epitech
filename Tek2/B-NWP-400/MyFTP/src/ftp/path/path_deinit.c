/*
** EPITECH PROJECT, 2024
** path_deinit.c
** File description:
** path_deinit.c
*/

#include "ftp/path.h"

#include <stdlib.h>

void path_deinit(path_t *self)
{
    free(self->root);
    free(self->path);
}
