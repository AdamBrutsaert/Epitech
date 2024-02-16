/*
** EPITECH PROJECT, 2023
** lexer_next.c
** File description:
** lexer_next.c
*/

#include "asm/lexer_impl.h"

token_t *lexer_next(lexer_t *lexer)
{
    token_t *token = vec_get(lexer->tokens, lexer->cursor);

    if (token == NULL)
        return NULL;
    lexer->cursor++;
    return token;
}
