/*
** EPITECH PROJECT, 2023
** lem_in_path_intersect.c
** File description:
** lem_in_path_intersect.c
*/

#include "lem_in_impl.h"

static bool interserct2(path_t *path1, path_t *path2, size_t i)
{
    size_t length2 = path_get_length(path2);

    for (size_t j = 0; j + 1 < length2; j++) {
        if (path_get_room(path1, i) == path_get_room(path2, j))
            return true;
    }
    return false;
}

static bool intersects(path_t *path1, path_t *path2)
{
    size_t length1 = path_get_length(path1);

    for (size_t i = 0; i + 1 < length1; i++) {
        if (interserct2(path1, path2, i))
            return true;
    }
    return false;
}

bool lem_in_path_intersect(lem_in_t *lem_in, path_t *path)
{
    for (size_t i = 0; i < lem_in->length; i++) {
        if (intersects(path, lem_in->paths[i]))
            return true;
    }
    return false;
}
