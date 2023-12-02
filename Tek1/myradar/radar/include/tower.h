/*
** EPITECH PROJECT, 2022
** tower.h
** File description:
** tower.h
*/

#pragma once

#include "aircraft.h"

#include <my/math/vector.h>

#define TOWER_WIDTH 13
#define TOWER_HEIGHT 47

typedef struct {
    vec2f_t position;
    float range;
} tower_t;

int8_t tower_intersects(tower_t *tower, aircraft_t *aircraft);
