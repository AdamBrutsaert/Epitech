/*
** EPITECH PROJECT, 2023
** parser_process_room.c.c
** File description:
** parser_process_room.c.c
*/

#include "lem_in/parser_impl.h"
#include "my/string.h"
#include "my/stdio.h"

static bool parse_name(char **line, room_t *room)
{
    char *begin = *line;
    char *name;

    while (**line != ' ')
        (*line)++;
    name = my_strndup(begin, *line - begin);
    if (name == NULL)
        return false;
    room_set_name(room, name);
    while (**line == ' ')
        (*line)++;
    return true;
}

static int32_t parse_coordinate(char **line)
{
    int32_t coordinate = 0;
    int8_t sign = 1;

    if (**line == '-') {
        sign = -1;
        (*line)++;
    }
    for (; **line >= '0' && **line <= '9'; (*line)++)
        coordinate = coordinate * 10 + sign * (**line - '0');
    while (**line == ' ')
        (*line)++;
    return coordinate;
}

static room_t *parse_room(parser_t *parser)
{
    char *line = parser->line;
    room_t *room;

    if (!parser_is_room(parser))
        return NULL;
    room = room_new();
    if (!parse_name(&line, room)) {
        room_delete(room);
        return NULL;
    }
    room_set_x(room, parse_coordinate(&line));
    room_set_y(room, parse_coordinate(&line));
    return room;
}

static bool process_start_end(parser_t *parser, room_t *room)
{
    if (parser->will_be_start
        && !anthill_set_start(parser->anthill, room_get_name(room)))
        return false;
    if (parser->will_be_end
        && !anthill_set_end(parser->anthill, room_get_name(room)))
        return false;
    return true;
}

bool parser_process_room(parser_t *parser)
{
    room_t *room = parse_room(parser);

    if (!room)
        return false;
    if (!anthill_add_room(parser->anthill, room)) {
        room_delete(room);
        return false;
    }
    if (!process_start_end(parser, room))
        return false;
    if (anthill_get_length(parser->anthill) == 1)
        my_puts("#rooms\n");
    if (parser->will_be_start)
        my_puts("##start\n");
    if (parser->will_be_end)
        my_puts("##end\n");
    parser->will_be_start = false;
    parser->will_be_end = false;
    parser_print_line_cleaned(parser->line);
    return true;
}
