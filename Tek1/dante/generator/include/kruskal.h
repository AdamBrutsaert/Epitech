/*
** EPITECH PROJECT, 2023
** kruskal.h
** File description:
** kruskal.h
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    KRUSKAL_WALL,
    KRUSKAL_EMPTY,
} kruskal_cell_type_t;

typedef struct kruskal_cell {
    struct kruskal_cell *parent;
    uint32_t rank;
    kruskal_cell_type_t type;
} kruskal_cell_t;

void kruskal_cell_make(kruskal_cell_t *cell, kruskal_cell_type_t type);
kruskal_cell_t *kruskal_cell_find(kruskal_cell_t *cell);
void kruskal_cell_union(kruskal_cell_t *c1, kruskal_cell_t *c2);

typedef struct {
    uint32_t x;
    uint32_t y;
} kruskal_wall_t;

typedef struct {
    kruskal_cell_t *cells;
    kruskal_wall_t *walls;
    uint32_t width;
    uint32_t height;
} kruskal_maze_t;

int kruskal_from_args(int argc, char **argv);

kruskal_maze_t *kruskal_maze_create(uint32_t width, uint32_t height);
void kruskal_maze_destroy(kruskal_maze_t *maze);

kruskal_cell_t *kruskal_maze_get(kruskal_maze_t *maze, int64_t x, int64_t y);
void kruskal_maze_generate(kruskal_maze_t *maze);

void kruskal_maze_print(kruskal_maze_t *maze);
void kruskal_maze_debug(kruskal_maze_t *maze);
