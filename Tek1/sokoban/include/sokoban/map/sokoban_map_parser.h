/*
** EPITECH PROJECT, 2022
** sokoban_map_parser.h
** File description:
** sokoban_map_parser.h
*/

#pragma once

#include "sokoban_map.h"

#define TOKEN_PLAYER    ('P')
#define TOKEN_OBJECTIVE ('O')
#define TOKEN_BOX       ('X')
#define TOKEN_WALL      ('#')
#define TOKEN_VOID      (' ')
#define TOKEN_NEWLINE   ('\n')

typedef struct {
    sokoban_map_t *map;
    char *iterator;
    u64_t current_row;
    u64_t player_count;
} sokoban_map_parser_t;

status_t sokoban_map_parse(sokoban_map_t *map, char *content);
void sokoban_map_parse_player(sokoban_map_parser_t *parser);
void sokoban_map_parse_newline(sokoban_map_parser_t *parser);
void sokoban_map_parse_objective(sokoban_map_parser_t *parser);
void sokoban_map_parse_box(sokoban_map_parser_t *parser);
