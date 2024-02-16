/*
** EPITECH PROJECT, 2022
** grid.h
** File description:
** grid.h
*/

#pragma once

#include "aircraft.h"

#include <my/vector.h>

typedef struct {
    aircraft_t **aircrafts;
    uint32_t length;
    uint32_t capacity;
} cell_t;

typedef struct {
    cell_t *cells;
    uint32_t precision;
} grid_t;

grid_t *grid_create(uint32_t precision);
void grid_destroy(grid_t *grid);

void grid_insert(grid_t *grid, aircraft_t *aircraft);
void grid_clear(grid_t *grid);
void grid_check_collisions(grid_t *grid, vector_t *towers);
