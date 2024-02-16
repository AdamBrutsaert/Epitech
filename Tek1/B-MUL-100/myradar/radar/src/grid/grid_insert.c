/*
** EPITECH PROJECT, 2022
** grid_insert.c
** File description:
** grid_insert.c
*/

#include "grid.h"

#include <my/memory.h>

int64_t get_cell(grid_t *grid, vec2f_t point)
{
    uint32_t x = point.x / (1920.0f / grid->precision);
    uint32_t y = point.y / (1080.0f / grid->precision);

    if (x >= grid->precision)
        x = grid->precision - 1;
    if (y >= grid->precision)
        y = grid->precision - 1;
    if (point.x < 0 || point.x > 1920.0f || point.y < 0 || point.y > 1080.0f)
        return -1;
    return y * grid->precision + x;
}

static void insert(cell_t *cell, aircraft_t *aircraft)
{
    if (cell->length == cell->capacity) {
        cell->capacity = cell->capacity * 2 + !cell->capacity;
        cell->aircrafts = my_realloc(cell->aircrafts, sizeof(aircraft_t *)
            * cell->capacity);
    }
    cell->aircrafts[cell->length] = aircraft;
    cell->length++;
}

void grid_insert(grid_t *grid, aircraft_t *aircraft)
{
    int64_t c1 = get_cell(grid, aircraft->ur);
    int64_t c2 = get_cell(grid, aircraft->ul);
    int64_t c3 = get_cell(grid, aircraft->bl);
    int64_t c4 = get_cell(grid, aircraft->br);

    if (c1 != -1)
        insert(&grid->cells[c1], aircraft);
    if (c2 != -1 && c2 != c1)
        insert(&grid->cells[c2], aircraft);
    if (c3 != -1 && c3 != c1 && c3 != c2)
        insert(&grid->cells[c3], aircraft);
    if (c4 != -1 && c4 != c1 && c4 != c2 && c4 != c3)
        insert(&grid->cells[c4], aircraft);
}
