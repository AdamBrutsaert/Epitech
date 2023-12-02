/*
** EPITECH PROJECT, 2023
** kruskal_maze_get.c
** File description:
** kruskal_maze_get.c
*/

#include "kruskal.h"

#include <stddef.h>

kruskal_cell_t *kruskal_maze_get(kruskal_maze_t *maze, int64_t x, int64_t y)
{
    if (x >= maze->width || y >= maze->height || x < 0 || y < 0)
        return NULL;
    return &maze->cells[y * maze->width + x];
}
