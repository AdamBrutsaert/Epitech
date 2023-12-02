/*
** EPITECH PROJECT, 2023
** parser_get_next_line.c
** File description:
** parser_get_next_line.c
*/

#include "lem_in/parser_impl.h"
#include "my/string.h"

#include <stdio.h>
#include <stdlib.h>

void parser_get_next_line(parser_t *parser)
{
    size_t length = 0;

    free(parser->line);
    parser->line = NULL;
    if (getline(&parser->line, &length, stdin) == -1) {
        free(parser->line);
        parser->line = NULL;
        return;
    }
    length = my_strlen(parser->line);
    if (length > 0 && parser->line[length - 1] == '\n')
        parser->line[length - 1] = '\0';
}
