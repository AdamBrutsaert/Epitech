/*
** EPITECH PROJECT, 2023
** naive_maze_destroy.c
** File description:
** naive_maze_destroy.c
*/

#include "naive.h"

#include <stdlib.h>

void naive_maze_destroy(naive_maze_t *maze)
{
    free(maze->cells);
    free(maze->walls);
    free(maze);
}
