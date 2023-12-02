/*
** EPITECH PROJECT, 2022
** sokoban_map_is_obstacle.c
** File description:
** sokoban_map_is_obstacle.c
*/

#include "sokoban/map/sokoban_map.h"
#include "my/string.h"

bool_t sokoban_map_is_obstacle(sokoban_map_t *map, u64_t row, u64_t column)
{
    if (row >= map->height)
        return true;
    if (column >= my_strlen(map->rows[row]))
        return true;
    return sokoban_map_get_box(map, row, column)
        || map->rows[row][column] == '#'
        || map->rows[row][column] == 'P';
}
