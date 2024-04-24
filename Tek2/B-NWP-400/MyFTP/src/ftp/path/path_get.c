/*
** EPITECH PROJECT, 2024
** path_get.c
** File description:
** path_get.c
*/

#include "ftp/path.h"

const char *path_get(path_t *self)
{
    return self->path;
}
