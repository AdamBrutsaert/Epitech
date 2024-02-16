/*
** EPITECH PROJECT, 2022
** sokoban_map_move_right.c
** File description:
** sokoban_map_move_right.c
*/

#include "sokoban/map/sokoban_map.h"
#include "my/string.h"

void sokoban_map_move_right(sokoban_map_t *map)
{
    position_t *box;

    if (map->player.column + 1 < my_strlen(map->rows[map->player.row]))
        box = sokoban_map_get_box(map, map->player.row,
            map->player.column + 1);
    if (box && sokoban_map_is_obstacle(map, map->player.row,
        map->player.column + 2))
        return;
    if (!box && sokoban_map_is_obstacle(map, map->player.row,
        map->player.column + 1))
        return;
    if (box)
        box->column++;
    map->player.column++;
}
