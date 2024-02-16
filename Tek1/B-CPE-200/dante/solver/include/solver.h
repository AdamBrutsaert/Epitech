/*
** EPITECH PROJECT, 2023
** solver.h
** File description:
** solver.h
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} direction_t;

typedef enum {
    UNVISITED = 0,
    WILL_VISIT,
    VISITED
} status_t;

typedef struct cell {
    direction_t previous;
    status_t visited;
} cell_t;

typedef struct {
    uint32_t x;
    uint32_t y;
} position_t;

typedef struct {
    position_t *positions;
    uint64_t length;
    uint64_t capacity;
} queue_t;

queue_t *queue_create(void);
void queue_destroy(queue_t *queue);

bool queue_push(queue_t *queue, uint32_t x, uint32_t y);
void queue_pop(queue_t *queue, position_t *position);

typedef struct {
    char *map;
    cell_t *cells;
    queue_t *queue;
    uint32_t width;
    uint32_t height;
} solver_t;

solver_t *solver_create(char *path);
void solver_destroy(solver_t *solver);

bool solver_solve(solver_t *solver);
void solver_reconstruct(solver_t *solver);
