/*
** EPITECH PROJECT, 2023
** kruskal_maze_generate.c
** File description:
** kruskal_maze_generate.c
*/

#include "kruskal.h"

#include <stdlib.h>
#include <unistd.h>

static bool is_unioned(kruskal_cell_t *c1, kruskal_cell_t *c2)
{
    return c1 != NULL && c2 != NULL
        && c1->type == KRUSKAL_EMPTY && c2->type == KRUSKAL_EMPTY
        && kruskal_cell_find(c1) == kruskal_cell_find(c2);
}

static bool are_neighbors_unioned(kruskal_maze_t *maze,
    kruskal_wall_t *wall)
{
    kruskal_cell_t *neighbor_w = kruskal_maze_get(maze, wall->x - 1, wall->y);
    kruskal_cell_t *neighbor_e = kruskal_maze_get(maze, wall->x + 1, wall->y);
    kruskal_cell_t *neighbor_s = kruskal_maze_get(maze, wall->x, wall->y + 1);
    kruskal_cell_t *neighbor_n = kruskal_maze_get(maze, wall->x, wall->y - 1);

    return is_unioned(neighbor_w, neighbor_n)
        || is_unioned(neighbor_w, neighbor_e)
        || is_unioned(neighbor_w, neighbor_s)
        || is_unioned(neighbor_n, neighbor_e)
        || is_unioned(neighbor_n, neighbor_s)
        || is_unioned(neighbor_e, neighbor_s);
}

static void union_cells(kruskal_cell_t *c1,
    kruskal_cell_t *c2)
{
    if (c1 != NULL && c1->type == KRUSKAL_EMPTY
        && c2 != NULL && c2->type == KRUSKAL_EMPTY)
        kruskal_cell_union(c1, c2);
}

static void try_break_wall(kruskal_maze_t *maze, uint32_t index)
{
    kruskal_wall_t *wall = &maze->walls[index];
    kruskal_cell_t *cell = kruskal_maze_get(maze, wall->x, wall->y);

    if (cell->type != KRUSKAL_WALL)
        return;
    if (wall->x % 2 == 1 && wall->y % 2 == 1)
        return;
    if (are_neighbors_unioned(maze, wall))
        return;
    cell->type = KRUSKAL_EMPTY;
    union_cells(cell, kruskal_maze_get(maze, wall->x - 1, wall->y));
    union_cells(cell, kruskal_maze_get(maze, wall->x + 1, wall->y));
    union_cells(cell, kruskal_maze_get(maze, wall->x, wall->y - 1));
    union_cells(cell, kruskal_maze_get(maze, wall->x, wall->y + 1));
}

void kruskal_maze_generate(kruskal_maze_t *maze)
{
    uint32_t count = 0;

    for (uint32_t i = 0; i < maze->width * maze->height; i++) {
        if (maze->cells[i].type == KRUSKAL_WALL)
            count++;
    }
    for (uint32_t i = 0; i < count; i++)
        try_break_wall(maze, i);
}
