/*
** EPITECH PROJECT, 2022
** sokoban_map_get_status.c
** File description:
** sokoban_map_get_status.c
*/

#include "sokoban/sokoban.h"

bool_t has_won(sokoban_map_t *map)
{
    position_t *objective;

    for (u64_t i = 0; i < map->objectives.length; i++) {
        objective = vector_get(&map->objectives, i);
        if (!sokoban_map_get_box(map, objective->row, objective->column))
            return false;
    }
    return true;
}

bool_t has_lost(sokoban_map_t *map)
{
    position_t *box;
    bool_t left;
    bool_t right;
    bool_t up;
    bool_t down;

    for (u32_t i = 0; i < map->boxes.length; i++) {
        box = vector_get(&map->boxes, i);
        left = box->column ?
            sokoban_map_is_obstacle(map, box->row, box->column - 1) : true;
        right = sokoban_map_is_obstacle(map, box->row, box->column + 1);
        up = box->row ?
            sokoban_map_is_obstacle(map, box->row - 1, box->column) : true;
        down = sokoban_map_is_obstacle(map, box->row + 1, box->column);
        if (!((up && right) || (right && down) || (down && left)
            || (left && up)))
            return false;
    }
    return true;
}

status_t sokoban_map_get_status(sokoban_map_t *map)
{
    if (has_won(map))
        return 0;
    if (has_lost(map))
        return 1;
    return -1;
}
