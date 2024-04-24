/*
** EPITECH PROJECT, 2024
** path_change_relative.c
** File description:
** path_change_relative.c
*/

#include "ftp/path.h"

#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>

/// Returns the next directory in the path and moves the pointer to the next
static char *next_directory(const char **path)
{
    const char *begin = *path;
    const char *end;

    while (**path != '\0' && **path != '/')
        (*path)++;
    end = *path;
    while (**path == '/')
        (*path)++;
    return strndup(begin, end - begin);
}

static bool change_relative(path_t *tmp, char *dir)
{
    if (dir == NULL)
        return false;
    if (strcmp(dir, ".") == 0)
        return true;
    if (strcmp(dir, "..") == 0) {
        path_change_up(tmp);
        return true;
    }
    return path_change_directory(tmp, dir);
}

bool path_change_relative(path_t *self, const char *path)
{
    char *dir;
    path_t tmp;

    if (path[0] == '\0')
        return false;
    if (!path_init_copy(&tmp, self))
        return false;
    while (*path != '\0') {
        dir = next_directory(&path);
        if (!change_relative(&tmp, dir)) {
            free(dir);
            path_deinit(&tmp);
            return false;
        }
        free(dir);
    }
    path_deinit(self);
    *self = tmp;
    return true;
}
