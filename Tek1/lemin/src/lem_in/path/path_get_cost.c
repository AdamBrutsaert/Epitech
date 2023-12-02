/*
** EPITECH PROJECT, 2023
** path_get_cost.c
** File description:
** path_get_cost.c
*/

#include "lem_in/path_impl.h"

size_t path_get_cost(path_t *path)
{
    if (path->length == 1)
        return 0;
    return path->ant_count + path->length;
}
