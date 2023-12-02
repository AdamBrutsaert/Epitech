/*
** EPITECH PROJECT, 2023
** lem_in_add_path.c
** File description:
** lem_in_add_path.c
*/

#include "lem_in_impl.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(lem_in_t *lem_in)
{
    size_t capacity = lem_in->capacity * 2 + !lem_in->capacity;
    path_t **paths = malloc(capacity * sizeof(path_t *));

    if (paths == NULL)
        return false;
    my_memcpy(paths, lem_in->paths, lem_in->length * sizeof(path_t *));
    free(lem_in->paths);
    lem_in->paths = paths;
    lem_in->capacity = capacity;
    return true;
}

bool lem_in_add_path(lem_in_t *lem_in, path_t *path)
{
    if (lem_in->length == lem_in->capacity && !grow(lem_in))
        return false;
    lem_in->paths[lem_in->length] = path;
    lem_in->length++;
    return true;
}
