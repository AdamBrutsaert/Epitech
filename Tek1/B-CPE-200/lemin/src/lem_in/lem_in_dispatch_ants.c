/*
** EPITECH PROJECT, 2023
** lem_in_dispatch_ants.c
** File description:
** lem_in_dispatch_ants.c
*/

#include "lem_in_impl.h"

static void dispatch_ant(lem_in_t *lem_in)
{
    size_t min_index = 0;
    size_t min_cost = path_get_cost(lem_in->paths[0]);
    path_t *path;

    for (size_t i = 0; i < lem_in->length; i++) {
        path = lem_in->paths[i];
        if (path_get_cost(path) < min_cost) {
            min_index = i;
            min_cost = path_get_cost(path);
        }
    }
    path_add_ant(lem_in->paths[min_index]);
}

void lem_in_dispatch_ants(lem_in_t *lem_in)
{
    size_t ant_count = anthill_get_ant_count(lem_in->anthill);

    for (size_t i = 0; i < ant_count; i++)
        dispatch_ant(lem_in);
}
