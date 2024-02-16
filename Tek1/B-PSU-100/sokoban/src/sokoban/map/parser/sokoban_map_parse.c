/*
** EPITECH PROJECT, 2022
** sokoban_map_parse.c
** File description:
** sokoban_map_parse.c
*/

#include "sokoban/map/sokoban_map_parser.h"

static bool_t token_is_valid(char c)
{
    return c == TOKEN_PLAYER || c == TOKEN_OBJECTIVE
        || c == TOKEN_BOX || c == TOKEN_WALL
        || c == TOKEN_VOID || c == TOKEN_NEWLINE;
}

static void sokoban_map_parser_create(sokoban_map_parser_t *parser,
    sokoban_map_t *map, char *content)
{
    parser->map = map;
    parser->iterator = content;
    parser->current_row = 0;
    parser->player_count = 0;
    parser->map->rows[0] = content;
}

static status_t sokoban_map_parser_result(sokoban_map_parser_t *parser)
{
    return !(!*parser->iterator
        && parser->player_count == 1
        && parser->map->objectives.length
        && parser->map->boxes.length >= parser->map->objectives.length);
}

status_t sokoban_map_parse(sokoban_map_t *map, char *content)
{
    sokoban_map_parser_t parser;

    sokoban_map_parser_create(&parser, map, content);
    for (; token_is_valid(*parser.iterator); parser.iterator++) {
        switch (*parser.iterator) {
            case TOKEN_PLAYER:
                sokoban_map_parse_player(&parser);
                break;
            case TOKEN_OBJECTIVE:
                sokoban_map_parse_objective(&parser);
                break;
            case TOKEN_BOX:
                sokoban_map_parse_box(&parser);
                break;
            case TOKEN_NEWLINE:
                sokoban_map_parse_newline(&parser);
        }
    }
    return sokoban_map_parser_result(&parser);
}
