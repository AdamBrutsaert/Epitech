/*
** EPITECH PROJECT, 2023
** naive_maze_generate.c
** File description:
** naive_maze_generate.c
*/

#include "naive.h"

static bool is_over(naive_maze_t *maze, uint32_t wall_broken)
{
    if (maze->width * maze->height < 3)
        return true;
    return naive_cell_find(&maze->cells[0])
        == naive_cell_find(&maze->cells[maze->width * maze->height - 1])
        && (float)wall_broken / (float)(maze->width * maze->height - 2) > 0.5;
}

static void break_wall(naive_maze_t *maze, uint32_t index)
{
    naive_wall_t *wall = &maze->walls[index];
    naive_cell_t *cell = naive_maze_get(maze, wall->x, wall->y);
    naive_cell_t *neighbor_w = naive_maze_get(maze, wall->x - 1, wall->y);
    naive_cell_t *neighbor_e = naive_maze_get(maze, wall->x + 1, wall->y);
    naive_cell_t *neighbor_n = naive_maze_get(maze, wall->x, wall->y - 1);
    naive_cell_t *neighbor_s = naive_maze_get(maze, wall->x, wall->y + 1);

    cell->type = NAIVE_EMPTY;
    if (neighbor_w && neighbor_w->type == NAIVE_EMPTY)
        naive_cell_union(cell, neighbor_w);
    if (neighbor_e && neighbor_e->type == NAIVE_EMPTY)
        naive_cell_union(cell, neighbor_e);
    if (neighbor_n && neighbor_n->type == NAIVE_EMPTY)
        naive_cell_union(cell, neighbor_n);
    if (neighbor_s && neighbor_s->type == NAIVE_EMPTY)
        naive_cell_union(cell, neighbor_s);
}

void naive_maze_generate(naive_maze_t *maze)
{
    for (uint32_t i = 0; !is_over(maze, i); i++)
        break_wall(maze, i);
}
