/*
** EPITECH PROJECT, 2023
** kruskal_maze_create.c
** File description:
** kruskal_maze_create.c
*/

#include "kruskal.h"

#include <stdlib.h>
#include <string.h>

static bool kruskal_maze_create_cells(kruskal_maze_t *maze)
{
    uint32_t row;
    uint32_t col;

    maze->cells = calloc(maze->width * maze->height, sizeof(kruskal_cell_t));
    if (maze->cells == NULL)
        return false;
    for (uint32_t i = 0; i < maze->width * maze->height; i++) {
        row = i / maze->width;
        col = i % maze->width;
        if ((row % 2 == 0 && col % 2 == 0)
            || (row + 1 == maze->height && col + 1 == maze->width)) {
            kruskal_cell_make(&maze->cells[i], KRUSKAL_EMPTY);
        } else {
            kruskal_cell_make(&maze->cells[i], KRUSKAL_WALL);
        }
    }
    return true;
}

static void kruskal_union_bottom_right(kruskal_maze_t *maze)
{
    kruskal_cell_t *br;
    kruskal_cell_t *c;

    if (maze->width < 1 || maze->height < 1)
        return;
    br = kruskal_maze_get(maze, maze->width - 1,
        maze->height - 1);
    if (maze->width >= 2) {
        c = kruskal_maze_get(maze, maze->width - 2,
        maze->height - 1);
        if (c->type == KRUSKAL_EMPTY)
            kruskal_cell_union(c, br);
    }
    if (maze->height >= 2) {
        c = kruskal_maze_get(maze, maze->width - 1,
        maze->height - 2);
        if (c->type == KRUSKAL_EMPTY)
            kruskal_cell_union(c, br);
    }
}

static bool kruskal_maze_create_walls(kruskal_maze_t *maze)
{
    uint32_t count = 0;
    uint32_t j = 0;

    for (uint32_t i = 0; i < maze->width * maze->height; i++) {
        if (maze->cells[i].type == KRUSKAL_WALL)
            count++;
    }
    maze->walls = calloc(count, sizeof(kruskal_wall_t));
    if (maze->walls == NULL)
        return false;
    for (uint32_t i = 0; i < maze->width * maze->height; i++) {
        if (maze->cells[i].type == KRUSKAL_WALL) {
            maze->walls[j].x = i % maze->width;
            maze->walls[j].y = i / maze->width;
            j++;
        }
    }
    return true;
}

static void kruskal_maze_shuffle_walls(kruskal_maze_t *maze)
{
    uint32_t count = 0;
    uint32_t j;
    kruskal_wall_t temp;

    for (uint32_t i = 0; i < maze->width * maze->height; i++) {
        if (maze->cells[i].type == KRUSKAL_WALL)
            count++;
    }
    if (count <= 1)
        return;
    for (uint32_t i = 0; i < count - 1; i++) {
        j = i + rand() / (RAND_MAX / (count - i) + 1);
        memcpy(&temp, &maze->walls[j], sizeof(kruskal_wall_t));
        memcpy(&maze->walls[j], &maze->walls[i], sizeof(kruskal_wall_t));
        memcpy(&maze->walls[i], &temp, sizeof(kruskal_wall_t));
    }
}

kruskal_maze_t *kruskal_maze_create(uint32_t width, uint32_t height)
{
    kruskal_maze_t *maze = calloc(1, sizeof(kruskal_maze_t));

    if (maze == NULL)
        return NULL;
    maze->width = width;
    maze->height = height;
    if (!kruskal_maze_create_cells(maze)) {
        kruskal_maze_destroy(maze);
        return NULL;
    }
    if (!kruskal_maze_create_walls(maze)) {
        kruskal_maze_destroy(maze);
        return NULL;
    }
    kruskal_union_bottom_right(maze);
    kruskal_maze_shuffle_walls(maze);
    return maze;
}
