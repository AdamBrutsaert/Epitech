/*
** EPITECH PROJECT, 2022
** grid_check_collisions.c
** File description:
** grid_check_collisions.c
*/

#include "grid.h"

#include "tower.h"

static int8_t is_in_tower_range(aircraft_t *aircraft, vector_t *towers)
{
    tower_t *tower;

    for (uint64_t i = 0; i < vector_length(towers); i++) {
        tower = vector_get(towers, i);
        if (tower_intersects(tower, aircraft))
            return 1;
    }
    return 0;
}

static void check_between(cell_t *cell, vector_t *towers, uint32_t i,
    uint32_t j)
{
    if (i == j)
        return;
    if (aircraft_intersects(cell->aircrafts[i], cell->aircrafts[j])) {
        if (!is_in_tower_range(cell->aircrafts[i], towers))
            cell->aircrafts[i]->hit = 1;
        if (!is_in_tower_range(cell->aircrafts[j], towers))
            cell->aircrafts[j]->hit = 1;
    }
}

static void check_cell(cell_t *cell, vector_t *towers)
{
    for (uint32_t i = 0; i < cell->length; i++)
        for (uint32_t j = 0; j < cell->length; j++)
            check_between(cell, towers, i, j);
}

void grid_check_collisions(grid_t *grid, vector_t *towers)
{
    for (uint32_t i = 0; i < grid->precision * grid->precision; i++)
        check_cell(&grid->cells[i], towers);
}
