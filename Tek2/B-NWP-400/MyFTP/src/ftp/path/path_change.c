/*
** EPITECH PROJECT, 2024
** path_change.c
** File description:
** path_change.c
*/

#include "ftp/path.h"

bool path_change(path_t *self, const char *path)
{
    if (path[0] == '/')
        return path_change_absolute(self, path);
    return path_change_relative(self, path);
}
