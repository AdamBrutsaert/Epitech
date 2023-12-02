/*
** EPITECH PROJECT, 2022
** sokoban_map.h
** File description:
** sokoban_map.h
*/

#pragma once

#include "my/vector.h"

typedef struct {
    u64_t row;
    u64_t column;
} position_t;

typedef struct {
    char const *name;
    u64_t width;
    u64_t height;
    char **rows;
    vector_t objectives;
    vector_t boxes;
    position_t player;
} sokoban_map_t;

status_t sokoban_map_create(sokoban_map_t *map, char const *name);
void sokoban_map_destroy(sokoban_map_t *map);

void sokoban_map_draw(sokoban_map_t *map);

position_t *sokoban_map_get_box(sokoban_map_t *map, u64_t row, u64_t column);
bool_t sokoban_map_is_obstacle(sokoban_map_t *map, u64_t row, u64_t column);

void sokoban_map_move_left(sokoban_map_t *map);
void sokoban_map_move_right(sokoban_map_t *map);
void sokoban_map_move_up(sokoban_map_t *map);
void sokoban_map_move_down(sokoban_map_t *map);

status_t sokoban_map_get_status(sokoban_map_t *map);
