/*
** EPITECH PROJECT, 2023
** parse_redirection.c
** File description:
** parse_redirection.c
*/

#include "shell/parser_impl.h"

static bool is_redirection(lexer_t *lexer)
{
    token_type_t type = lexer_peek_type(lexer, 0);

    return type == TOKEN_LEFT_CHEVRON
        || type == TOKEN_DOUBLE_LEFT_CHEVRON
        || type == TOKEN_RIGHT_CHEVRON
        || type == TOKEN_DOUBLE_RIGHT_CHEVRON;
}

static redirection_t *get_redirection(lexer_t *lexer)
{
    token_t *first = lexer_next(lexer);
    token_t *second = lexer_next(lexer);
    redirection_type_t type;

    if (second == NULL || token_get_type(second) != TOKEN_STRING)
        return NULL;
    if (token_get_type(first) == TOKEN_LEFT_CHEVRON)
        type = REDIRECTION_INPUT;
    if (token_get_type(first) == TOKEN_DOUBLE_LEFT_CHEVRON)
        type = REDIRECTION_HERE_DOCUMENT;
    if (token_get_type(first) == TOKEN_RIGHT_CHEVRON)
        type = REDIRECTION_OUTPUT;
    if (token_get_type(first) == TOKEN_DOUBLE_RIGHT_CHEVRON)
        type = REDIRECTION_APPEND;
    return redirection_new(type, token_get_value(second));
}

bool parse_redirection(lexer_t *lexer, instruction_t *instruction)
{
    redirection_t *redirection;

    if (!is_redirection(lexer))
        return true;
    redirection = get_redirection(lexer);
    if (redirection == NULL)
        return false;
    if (!instruction_push_redirection(instruction, redirection)) {
        redirection_delete(redirection);
        return false;
    }
    return true;
}
