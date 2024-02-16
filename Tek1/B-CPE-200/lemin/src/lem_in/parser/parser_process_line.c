/*
** EPITECH PROJECT, 2023
** parser_process_line.c.c
** File description:
** parser_process_line.c.c
*/

#include "lem_in/parser_impl.h"
#include "my/string.h"

static bool process_state(parser_t *parser)
{
    switch (parser->state) {
    case PARSING_ANT_COUNT:
        if (!parser_process_ant_count(parser))
            return false;
        parser->state = PARSING_ROOMS;
        break;
    case PARSING_ROOMS:
        if (!parser_process_room(parser)) {
            parser->state = PARSING_TUNNELS;
            return true;
        }
        break;
    case PARSING_TUNNELS:
        if (!parser_process_tunnel(parser))
            return false;
        break;
    }
    parser_get_next_line(parser);
    return true;
}

bool parser_process_line(parser_t *parser)
{
    if (parser->state == PARSING_ROOMS && parser_is_command(parser)) {
        if (!my_strcmp(parser->line, "##start"))
            parser->will_be_start = true;
        if (!my_strcmp(parser->line, "##end"))
            parser->will_be_end = true;
        parser_get_next_line(parser);
        return true;
    }
    if (parser_is_comment(parser)) {
        parser_get_next_line(parser);
        return true;
    }
    if (parser->state == PARSING_TUNNELS
        && (anthill_get_start(parser->anthill) == NULL
            || anthill_get_end(parser->anthill) == NULL))
        return false;
    return process_state(parser);
}
