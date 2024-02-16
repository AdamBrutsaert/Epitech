/*
** EPITECH PROJECT, 2022
** tower_intersects.c
** File description:
** tower_intersects.c
*/

#include "tower.h"

static int8_t is_point_inside(tower_t *tower, vec2f_t point)
{
    float dx = tower->position.x - point.x;
    float dy = tower->position.y - point.y;

    return dx * dx + dy * dy <= tower->range * tower->range;
}

int8_t tower_intersects(tower_t *tower, aircraft_t *aircraft)
{
    return is_point_inside(tower, aircraft->ul)
        || is_point_inside(tower, aircraft->ur)
        || is_point_inside(tower, aircraft->bl)
        || is_point_inside(tower, aircraft->br);
}
