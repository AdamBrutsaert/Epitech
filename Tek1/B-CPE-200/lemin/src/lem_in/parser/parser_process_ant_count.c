/*
** EPITECH PROJECT, 2023
** parser_process_ant_count.c.c
** File description:
** parser_process_ant_count.c.c
*/

#include "lem_in/parser_impl.h"
#include "my/stdio.h"

static bool is_valid_ant_count(char *line)
{
    while (*line >= '0' && *line <= '9')
        line++;
    while (*line == ' ')
        line++;
    return *line == '\0' || *line == '#';
}

static size_t get_ant_count(char *line)
{
    size_t count = 0;

    for (; *line >= '0' && *line <= '9'; line++)
        count = count * 10 + *line - '0';
    return count;
}

bool parser_process_ant_count(parser_t *parser)
{
    if (!is_valid_ant_count(parser->line))
        return false;
    anthill_set_ant_count(parser->anthill, get_ant_count(parser->line));
    my_puts("#number_of_ants\n");
    parser_print_line_cleaned(parser->line);
    return true;
}
