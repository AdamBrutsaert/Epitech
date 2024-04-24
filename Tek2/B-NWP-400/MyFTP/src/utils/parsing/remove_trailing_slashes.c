/*
** EPITECH PROJECT, 2024
** remove_trailing_slashes.c
** File description:
** remove_trailing_slashes.c
*/

#include "utils/parsing.h"

#include <string.h>

char *remove_trailing_slashes(char *path)
{
    size_t len = strlen(path);

    for (; len > 1 && path[len - 1] == '/'; len--)
        path[len - 1] = '\0';
    return path;
}
