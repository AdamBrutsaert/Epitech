/*
** EPITECH PROJECT, 2022
** sokoban_map_parse_newline.c
** File description:
** sokoban_map_parse_newline.c
*/

#include "sokoban/map/sokoban_map_parser.h"

void sokoban_map_parse_newline(sokoban_map_parser_t *parser)
{
    *parser->iterator = '\0';
    parser->current_row++;
    parser->map->rows[parser->current_row] = parser->iterator + 1;
}
