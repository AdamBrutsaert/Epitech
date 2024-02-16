/*
** EPITECH PROJECT, 2022
** aircraft.h
** File description:
** aircraft.h
*/

#pragma once

#include <my/math/vector.h>

#define AIRCRAFT_SIZE 20

typedef struct {
    // Transform
    vec2f_t center;
    float angle;

    vec2f_t ul;
    vec2f_t ur;
    vec2f_t bl;
    vec2f_t br;

    // Physics
    vec2f_t velocity;
    float distance;
    float flown;
    float delay;
    int8_t hit;
} aircraft_t;

void aircraft_init_transform(aircraft_t *aircraft, vec2f_t center, float angle);
void aircraft_init_physics(aircraft_t *aircraft, vec2f_t velocity,
    float distance, float delay);

int8_t aircraft_intersects(aircraft_t *aircraft, aircraft_t *other);
