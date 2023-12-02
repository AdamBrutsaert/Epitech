/*
** EPITECH PROJECT, 2023
** lexer_peek_type.c
** File description:
** lexer_peek_type.c
*/

#include "shell/lexer_impl.h"

token_type_t lexer_peek_type(lexer_t *lexer, size_t n)
{
    token_t *token = lexer_peek(lexer, n);

    if (token == NULL)
        return TOKEN_END;
    return token_get_type(token);
}
