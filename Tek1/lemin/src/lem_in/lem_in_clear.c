/*
** EPITECH PROJECT, 2023
** lem_in_clear.c
** File description:
** lem_in_clear.c
*/

#include "lem_in_impl.h"

#include <stdlib.h>

void lem_in_clear(lem_in_t *lem_in)
{
    queue_delete(lem_in->queue);
    for (size_t i = 0; i < lem_in->length; i++)
        path_delete(lem_in->paths[i]);
    free(lem_in->paths);
}
