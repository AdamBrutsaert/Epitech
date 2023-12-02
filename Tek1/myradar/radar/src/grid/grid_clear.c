/*
** EPITECH PROJECT, 2022
** grid_clear.c
** File description:
** grid_clear.c
*/

#include "grid.h"

void grid_clear(grid_t *grid)
{
    for (uint32_t i = 0; i < grid->precision * grid->precision; i++)
        grid->cells[i].length = 0;
}
