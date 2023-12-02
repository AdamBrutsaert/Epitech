/*
** EPITECH PROJECT, 2022
** sokoban.h
** File description:
** sokoban.h
*/

#pragma once

#include "map/sokoban_map.h"

status_t sokoban(int argc, char **argv, char **env);
status_t sokoban_help(char *program);

status_t sokoban_run(sokoban_map_t *map);
status_t sokoban_process_input(sokoban_map_t *map, i32_t input);
