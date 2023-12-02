/*
** EPITECH PROJECT, 2022
** sokoban_map_parse_player.c
** File description:
** sokoban_map_parse_player.c
*/

#include "sokoban/map/sokoban_map_parser.h"

void sokoban_map_parse_player(sokoban_map_parser_t *parser)
{
    *parser->iterator = ' ';
    parser->map->player.row = parser->current_row;
    parser->map->player.column = parser->iterator
        - parser->map->rows[parser->current_row];
    parser->player_count++;
}
