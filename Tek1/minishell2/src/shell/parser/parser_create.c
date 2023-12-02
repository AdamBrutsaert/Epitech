/*
** EPITECH PROJECT, 2023
** parser_create.c
** File description:
** parser_create.c
*/

#include "shell/parser.h"

#include <stdlib.h>

parser_t *parser_create(lexer_t *lexer)
{
    parser_t *parser = malloc(sizeof(parser_t));

    if (parser == NULL)
        return NULL;
    parser->lexer = lexer;
    return parser;
}
