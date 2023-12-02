/*
** EPITECH PROJECT, 2022
** sokoban_process_input.c
** File description:
** sokoban_process_input.c
*/

#include "sokoban/sokoban.h"

#include <ncurses.h>

status_t sokoban_process_input(sokoban_map_t *map, i32_t input)
{
    if (input == KEY_LEFT)
        sokoban_map_move_left(map);
    if (input == KEY_RIGHT)
        sokoban_map_move_right(map);
    if (input == KEY_UP)
        sokoban_map_move_up(map);
    if (input == KEY_DOWN)
        sokoban_map_move_down(map);
    if (input == ' ') {
        sokoban_map_destroy(map);
        return sokoban_map_create(map, map->name);
    }
    return 0;
}
