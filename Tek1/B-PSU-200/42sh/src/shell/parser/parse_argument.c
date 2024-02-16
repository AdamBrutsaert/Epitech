/*
** EPITECH PROJECT, 2023
** parse_argument.c
** File description:
** parse_argument.c
*/

#include "shell/parser_impl.h"

bool parse_argument(lexer_t *lexer, instruction_t *instruction)
{
    token_t *token;

    if (lexer_peek_type(lexer, 0) != TOKEN_STRING)
        return true;
    token = lexer_next(lexer);
    return instruction_push_argument(instruction, token_get_value(token));
}
