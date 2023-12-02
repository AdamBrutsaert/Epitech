/*
** EPITECH PROJECT, 2023
** parse_separator.c
** File description:
** parse_separator.c
*/

#include "shell/parser_impl.h"

separator_t parse_separator(lexer_t *lexer)
{
    token_type_t type = lexer_peek_type(lexer, 0);
    separator_t separator = SEPARATOR_NONE;

    if (type == TOKEN_SEMICOLON)
        separator = SEPARATOR_SEMICOLON;
    if (type == TOKEN_DOUBLE_AMPERSAND)
        separator = SEPARATOR_AND;
    if (type == TOKEN_DOUBLE_PIPE)
        separator = SEPARATOR_OR;
    if (separator != SEPARATOR_NONE)
        lexer_next(lexer);
    return separator;
}
