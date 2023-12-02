/*
** EPITECH PROJECT, 2022
** grid_destroy.c
** File description:
** grid_destroy.c
*/

#include "grid.h"

#include <my/memory.h>

void grid_destroy(grid_t *grid)
{
    for (uint32_t i = 0; i < grid->precision * grid->precision; i++)
        my_free(grid->cells[i].aircrafts);
    my_free(grid->cells);
    my_free(grid);
}
