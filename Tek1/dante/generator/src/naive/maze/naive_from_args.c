/*
** EPITECH PROJECT, 2023
** naive_from_args.c
** File description:
** naive_from_args.c
*/

#include "naive.h"

#include <stdlib.h>
#include <errno.h>

static bool naive_parse_args(int argc, char **argv, uint32_t *width,
    uint32_t *height)
{
    char *end;

    if (argc != 3)
        return false;
    *width = strtoul(argv[1], &end, 10);
    if (*end != '\0')
        return false;
    *height = strtoul(argv[2], &end, 10);
    if (*end != '\0')
        return false;
    return true;
}

int naive_from_args(int argc, char **argv)
{
    uint32_t width;
    uint32_t height;
    naive_maze_t *maze;

    if (!naive_parse_args(argc, argv, &width, &height))
        return 84;
    if (width < 1 || height < 1)
        return 84;
    maze = naive_maze_create(width, height);
    if (maze == NULL)
        return 84;
    naive_maze_generate(maze);
    naive_maze_print(maze);
    naive_maze_destroy(maze);
    return 0;
}
