/*
** EPITECH PROJECT, 2022
** grid_create.c
** File description:
** grid_create.c
*/

#include "grid.h"

#include <my/memory.h>

grid_t *grid_create(uint32_t precision)
{
    grid_t *grid = my_malloc(sizeof(grid_t));

    grid->precision = precision + !precision;
    grid->cells = my_calloc(sizeof(cell_t) * grid->precision * grid->precision);
    return grid;
}
