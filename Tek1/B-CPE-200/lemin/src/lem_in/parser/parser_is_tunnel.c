/*
** EPITECH PROJECT, 2023
** parser_is_tunnel.c
** File description:
** parser_is_tunnel.c
*/

#include "lem_in/parser_impl.h"

static bool skip_name(char **line)
{
    if (**line == ' ' || **line == '\0' || **line == '-')
        return false;
    while (**line != ' ' && **line != '\0' && **line != '-')
        (*line)++;
    return true;
}

bool parser_is_tunnel(parser_t *parser)
{
    char *line = parser->line;

    if (!skip_name(&line))
        return false;
    if (*line != '-')
        return false;
    line++;
    if (!skip_name(&line))
        return false;
    while (*line == ' ')
        line++;
    return *line == '\0' || *line == '#';
}
