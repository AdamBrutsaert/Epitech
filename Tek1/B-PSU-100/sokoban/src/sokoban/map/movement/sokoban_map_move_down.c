/*
** EPITECH PROJECT, 2022
** sokoban_map_move_down.c
** File description:
** sokoban_map_move_down.c
*/

#include "sokoban/map/sokoban_map.h"
#include "my/string.h"

void sokoban_map_move_down(sokoban_map_t *map)
{
    position_t *box;

    if (map->player.row + 1 < map->height)
        box = sokoban_map_get_box(map, map->player.row + 1,
            map->player.column);
    if (box && sokoban_map_is_obstacle(map, map->player.row + 2,
        map->player.column))
        return;
    if (!box && sokoban_map_is_obstacle(map, map->player.row + 1,
        map->player.column))
        return;
    if (box)
        box->row++;
    map->player.row++;
}
