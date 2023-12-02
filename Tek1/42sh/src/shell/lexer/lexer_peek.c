/*
** EPITECH PROJECT, 2023
** lexer_peek.c
** File description:
** lexer_peek.c
*/

#include "shell/lexer_impl.h"

token_t *lexer_peek(lexer_t *lexer, size_t n)
{
    if (lexer->cursor + n >= VEC_LEN(lexer->tokens))
        return NULL;
    return VEC_GET(lexer->tokens, lexer->cursor + n, token_t *);
}
