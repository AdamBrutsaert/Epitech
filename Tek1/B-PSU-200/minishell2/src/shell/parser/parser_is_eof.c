/*
** EPITECH PROJECT, 2023
** parser_is_eof.c
** File description:
** parser_is_eof.c
*/

#include "shell/parser.h"

bool parser_is_eof(parser_t *parser)
{
    return lexer_is_eof(parser->lexer);
}
