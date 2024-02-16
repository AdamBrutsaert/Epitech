/*
** EPITECH PROJECT, 2022
** sokoban_map_get_box.c
** File description:
** sokoban_map_get_box.c
*/

#include "sokoban/map/sokoban_map.h"

position_t *sokoban_map_get_box(sokoban_map_t *map, u64_t row, u64_t column)
{
    position_t *pos;

    for (u64_t i = 0; i < map->boxes.length; i++) {
        pos = vector_get(&map->boxes, i);
        if (pos->row == row && pos->column == column)
            return pos;
    }
    return nullptr;
}
