/*
** EPITECH PROJECT, 2023
** imperfect.h
** File description:
** imperfect.h
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    NAIVE_WALL,
    NAIVE_EMPTY,
} naive_cell_type_t;

typedef struct naive_cell {
    struct naive_cell *parent;
    uint32_t rank;
    naive_cell_type_t type;
} naive_cell_t;

void naive_cell_make(naive_cell_t *cell, naive_cell_type_t type);
naive_cell_t *naive_cell_find(naive_cell_t *cell);
void naive_cell_union(naive_cell_t *c1, naive_cell_t *c2);

typedef struct {
    uint32_t x;
    uint32_t y;
} naive_wall_t;

typedef struct {
    naive_cell_t *cells;
    naive_wall_t *walls;
    uint32_t width;
    uint32_t height;
} naive_maze_t;

int naive_from_args(int argc, char **argv);

naive_maze_t *naive_maze_create(uint32_t width, uint32_t height);
void naive_maze_destroy(naive_maze_t *maze);

naive_cell_t *naive_maze_get(naive_maze_t *maze, int64_t x, int64_t y);
void naive_maze_generate(naive_maze_t *maze);
void naive_maze_print(naive_maze_t *maze);
