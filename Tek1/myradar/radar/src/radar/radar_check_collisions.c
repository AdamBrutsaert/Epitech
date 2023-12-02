/*
** EPITECH PROJECT, 2022
** radar_check_collisions.c
** File description:
** radar_check_collisions.c
*/

#include "radar.h"

void radar_check_collisions(radar_t *radar)
{
    grid_clear(radar->grid);

    for (uint64_t i = 0; i < vector_length(radar->moving_aircrafts); i++)
        grid_insert(radar->grid, vector_get(radar->moving_aircrafts, i));
    grid_check_collisions(radar->grid, radar->towers);
}
