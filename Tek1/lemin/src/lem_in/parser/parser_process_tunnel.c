/*
** EPITECH PROJECT, 2023
** parser_process_tunnel.c
** File description:
** parser_process_tunnel.c
*/

#include "lem_in/parser_impl.h"
#include "my/string.h"
#include "my/stdio.h"

#include <stdlib.h>

static char *get_name(char **line)
{
    char *begin = *line;

    while (**line != '-' && **line != ' ' && **line != '\0')
        (*line)++;
    (**line) = '\0';
    (*line)++;
    return begin;
}

static void print_line(parser_t *parser)
{
    static bool is_first = true;

    if (is_first) {
        my_puts("#tunnels\n");
        is_first = false;
    }
    parser_print_line_cleaned(parser->line);
}

bool parser_process_tunnel(parser_t *parser)
{
    char *line = my_strdup(parser->line);
    char *name1;
    char *name2;

    if (line == NULL)
        return false;
    if (!parser_is_tunnel(parser))
        return false;
    name1 = get_name(&line);
    name2 = get_name(&line);
    if (!anthill_add_tunnel(parser->anthill, name1, name2)) {
        free(name1);
        return false;
    }
    free(name1);
    print_line(parser);
    return true;
}
