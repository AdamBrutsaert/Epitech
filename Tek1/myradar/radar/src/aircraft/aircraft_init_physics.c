/*
** EPITECH PROJECT, 2022
** aircraft_init_physics.c
** File description:
** aircraft_init_physics.c
*/

#include "aircraft.h"

void aircraft_init_physics(aircraft_t *aircraft, vec2f_t velocity,
    float distance, float delay)
{
    aircraft->velocity = velocity;
    aircraft->distance = distance;
    aircraft->flown = 0;
    aircraft->delay = delay;
    aircraft->hit = 0;
}
