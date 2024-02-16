/*
** EPITECH PROJECT, 2023
** parser_destroy.c
** File description:
** parser_destroy.c
*/

#include "shell/parser.h"

#include <stdlib.h>

void parser_destroy(parser_t *parser)
{
    if (parser == NULL)
        return;
    free(parser);
}
