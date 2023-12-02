/*
** EPITECH PROJECT, 2022
** sokoban_map_move_up.c
** File description:
** sokoban_map_move_up.c
*/

#include "sokoban/map/sokoban_map.h"
#include "my/string.h"

void sokoban_map_move_up(sokoban_map_t *map)
{
    position_t *box;

    if (map->player.row > 1)
        box = sokoban_map_get_box(map, map->player.row - 1,
            map->player.column);
    if (map->player.row == 0)
        return;
    if (box && sokoban_map_is_obstacle(map, map->player.row - 2,
        map->player.column))
        return;
    if (!box && sokoban_map_is_obstacle(map, map->player.row - 1,
        map->player.column))
        return;
    if (box)
        box->row--;
    map->player.row--;
}
