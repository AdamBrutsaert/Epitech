/*
** EPITECH PROJECT, 2023
** lexer_peek_type.c
** File description:
** lexer_peek_type.c
*/

#include "asm/lexer_impl.h"

token_type_t lexer_peek_type(lexer_t *lexer, size_t offset)
{
    token_t *token = vec_get(lexer->tokens, lexer->cursor + offset);

    if (token == NULL)
        return TOKEN_EOF;
    return token->type;
}
