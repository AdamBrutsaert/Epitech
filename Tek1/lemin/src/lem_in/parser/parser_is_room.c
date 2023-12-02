/*
** EPITECH PROJECT, 2023
** parser_is_room.c
** File description:
** parser_is_room.c
*/

#include "lem_in/parser_impl.h"

static bool skip_name(char **line)
{
    if (**line == ' ' || **line == '\0')
        return false;
    while (**line != ' ' && **line != '\0')
        (*line)++;
    return true;
}

static bool skip_number(char **line)
{
    if (**line == '-')
        (*line)++;
    if (**line < '0' || **line > '9')
        return false;
    while (**line >= '0' && **line <= '9')
        (*line)++;
    return true;
}

static void skip_whitespace(char **line)
{
    while (**line == ' ')
        (*line)++;
}

bool parser_is_room(parser_t *parser)
{
    char *line = parser->line;

    if (!skip_name(&line))
        return false;
    skip_whitespace(&line);
    if (!skip_number(&line))
        return false;
    skip_whitespace(&line);
    if (!skip_number(&line))
        return false;
    skip_whitespace(&line);
    return *line == '#' || *line == '\0';
}
