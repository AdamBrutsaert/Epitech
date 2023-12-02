/*
** EPITECH PROJECT, 2023
** parse.c
** File description:
** parse.c
*/

#include "lem_in/parser_impl.h"

#include <stdlib.h>

anthill_t *parse(void)
{
    parser_t parser;

    parser.anthill = anthill_new();
    if (parser.anthill == NULL)
        return NULL;
    parser.state = PARSING_ANT_COUNT;
    parser.line = NULL;
    parser.will_be_start = false;
    parser.will_be_end = false;
    parser_get_next_line(&parser);
    while (parser.line != NULL) {
        if (!parser_process_line(&parser))
            break;
    }
    free(parser.line);
    return parser.anthill;
}
