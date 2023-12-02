/*
** EPITECH PROJECT, 2022
** sokoban_map_parse_objective.c
** File description:
** sokoban_map_parse_objective.c
*/

#include "sokoban/map/sokoban_map_parser.h"

void sokoban_map_parse_objective(sokoban_map_parser_t *parser)
{
    position_t pos = {
        .row = parser->current_row,
        .column = parser->iterator - parser->map->rows[parser->current_row]
    };

    *parser->iterator = ' ';
    vector_push(&parser->map->objectives, &pos);
}
