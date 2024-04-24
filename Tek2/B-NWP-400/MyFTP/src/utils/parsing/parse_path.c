/*
** EPITECH PROJECT, 2024
** parse_path.c
** File description:
** parse_path.c
*/

#include "utils/parsing.h"

#include <stdlib.h>
#include <string.h>

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

static void append_directory(char *path, char *directory)
{
    size_t length = strlen(path);
    size_t offset = path[0] == '/';

    if (strcmp(directory, ".") == 0)
        return;
    if (strcmp(directory, "..") == 0) {
        for (; length > offset && path[length - 1] != '/'; length--)
            path[length - 1] = '\0';
        if (length > offset && path[length - 1] == '/')
            path[length - 1] = '\0';
        return;
    }
    if (length != 0 && (length != 1 || path[0] != '/'))
        strcat(path, "/");
    strcat(path, directory);
}

char *parse_path(const char *path)
{
    char *new_path = calloc(strlen(path) + 1, sizeof(char));
    char *dir;

    if (new_path == NULL)
        return NULL;
    if (path[0] == '/') {
        path++;
        new_path[0] = '/';
    }
    while (*path != '\0') {
        dir = next_directory(&path);
        if (dir == NULL) {
            free(new_path);
            return NULL;
        }
        append_directory(new_path, dir);
        free(dir);
    }
    return new_path;
}
