/*
** EPITECH PROJECT, 2023
** lem_in_solve.c
** File description:
** lem_in_solve.c
*/

#include "lem_in_impl.h"

#include <stdlib.h>

bool lem_in_solve(anthill_t *anthill)
{
    lem_in_t lem_in;

    lem_in.anthill = anthill;
    lem_in.queue = queue_new();
    lem_in.paths = NULL;
    lem_in.length = 0;
    lem_in.capacity = 0;
    if (lem_in.queue == NULL)
        return false;
    if (!lem_in_find_paths(&lem_in)) {
        lem_in_clear(&lem_in);
        return false;
    }
    lem_in_dispatch_ants(&lem_in);
    lem_in_advance(&lem_in);
    lem_in_clear(&lem_in);
    return true;
}
