/*
** EPITECH PROJECT, 2022
** aircraft_init_transform.c
** File description:
** aircraft_init_transform.c
*/

#include "aircraft.h"

#include <math.h>

static vec2f_t apply_rotation(vec2f_t point, vec2f_t center, float angle)
{
    vec2f_t rotated;

    rotated.x = (point.x - center.x) * cos(angle) - (point.y - center.y) *
        sin(angle) + center.x;
    rotated.y = (point.x - center.x) * sin(angle) + (point.y - center.y) *
        cos(angle) + center.y;
    return rotated;
}

void aircraft_init_transform(aircraft_t *aircraft, vec2f_t center, float angle)
{
    aircraft->center = center;
    aircraft->angle = angle;
    aircraft->ul = apply_rotation((vec2f_t) { center.x - AIRCRAFT_SIZE / 2.0f,
        center.y - AIRCRAFT_SIZE / 2.0f }, center, angle);
    aircraft->ur = apply_rotation((vec2f_t) { center.x + AIRCRAFT_SIZE / 2.0f,
        center.y - AIRCRAFT_SIZE / 2.0f }, center, angle);
    aircraft->bl = apply_rotation((vec2f_t) { center.x - AIRCRAFT_SIZE / 2.0f,
        center.y + AIRCRAFT_SIZE / 2.0f }, center, angle);
    aircraft->br = apply_rotation((vec2f_t) { center.x + AIRCRAFT_SIZE / 2.0f,
        center.y + AIRCRAFT_SIZE / 2.0f }, center, angle);
}
