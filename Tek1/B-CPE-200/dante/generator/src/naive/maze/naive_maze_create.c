/*
** EPITECH PROJECT, 2023
** naive_maze_create.c
** File description:
** naive_maze_create.c
*/

#include "naive.h"

#include <stdlib.h>
#include <string.h>

static bool naive_maze_create_cells(naive_maze_t *maze)
{
    maze->cells = calloc(maze->width * maze->height, sizeof(naive_cell_t));
    if (maze->cells == NULL)
        return false;
    for (uint32_t i = 0; i < maze->height; i++) {
        for (uint32_t j = 0; j < maze->width; j++)
            naive_cell_make(&maze->cells[i * maze->width + j], NAIVE_WALL);
    }
    naive_cell_make(&maze->cells[0], NAIVE_EMPTY);
    naive_cell_make(&maze->cells[maze->width * maze->height - 1], NAIVE_EMPTY);
    return true;
}

static bool naive_maze_create_walls(naive_maze_t *maze)
{
    if (maze->width * maze->height < 3)
        return true;
    maze->walls = calloc(maze->width * maze->height - 2, sizeof(naive_wall_t));
    if (maze->walls == NULL)
        return false;
    for (uint32_t i = 1; i < maze->width * maze->height - 1; i++) {
        maze->walls[i - 1].x = i % maze->width;
        maze->walls[i - 1].y = i / maze->width;
    }
    return true;
}

static void naive_maze_shuffle_walls(naive_maze_t *maze)
{
    uint32_t j;
    naive_wall_t temp;
    uint32_t count;

    if (maze->width * maze->height < 3)
        return;
    count = maze->width * maze->height - 2;
    for (uint32_t i = 0; i < count - 1; i++) {
        j = i + rand() / (RAND_MAX / (count - i) + 1);
        memcpy(&temp, &maze->walls[j], sizeof(naive_wall_t));
        memcpy(&maze->walls[j], &maze->walls[i], sizeof(naive_wall_t));
        memcpy(&maze->walls[i], &temp, sizeof(naive_wall_t));
    }
}

static void naive_maze_union_glued(naive_maze_t *maze)
{
    if (maze->width * maze->height == 2)
        naive_cell_union(&maze->cells[0], &maze->cells[1]);
}

naive_maze_t *naive_maze_create(uint32_t width, uint32_t height)
{
    naive_maze_t *maze = calloc(1, sizeof(naive_maze_t));

    if (maze == NULL)
        return NULL;
    maze->width = width;
    maze->height = height;
    if (!naive_maze_create_cells(maze)) {
        naive_maze_destroy(maze);
        return NULL;
    }
    if (!naive_maze_create_walls(maze)) {
        naive_maze_destroy(maze);
        return NULL;
    }
    naive_maze_shuffle_walls(maze);
    naive_maze_union_glued(maze);
    return maze;
}
