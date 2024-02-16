/*
** EPITECH PROJECT, 2023
** lexer_next_value.c
** File description:
** lexer_next_value.c
*/

#include "asm/lexer_impl.h"

string_t *lexer_next_value(lexer_t *lexer)
{
    token_t *token = lexer_next(lexer);

    if (token == NULL)
        return NULL;
    return token->value;
}
