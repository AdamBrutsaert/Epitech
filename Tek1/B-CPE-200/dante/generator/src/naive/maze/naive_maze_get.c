/*
** EPITECH PROJECT, 2023
** naive_maze_get.c
** File description:
** naive_maze_get.c
*/

#include "naive.h"

#include <stddef.h>

naive_cell_t *naive_maze_get(naive_maze_t *maze, int64_t x, int64_t y)
{
    if (x >= maze->width || y >= maze->height || x < 0 || y < 0)
        return NULL;
    return &maze->cells[y * maze->width + x];
}
