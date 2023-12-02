/*
** EPITECH PROJECT, 2023
** path_delete.c
** File description:
** path_delete.c
*/

#include "lem_in/path_impl.h"

#include <stdlib.h>

void path_delete(path_t *path)
{
    if (path == NULL)
        return;
    for (size_t i = 0; i < path->ant_length; i++)
        ant_delete(path->ants[i]);
    free(path->ants);
    free(path->rooms);
    free(path);
}
