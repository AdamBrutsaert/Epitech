/*
** EPITECH PROJECT, 2023
** lexer_next.c
** File description:
** lexer_next.c
*/

#include "shell/lexer_impl.h"

token_t *lexer_next(lexer_t *lexer)
{
    if (lexer->cursor >= VEC_LEN(lexer->tokens))
        return NULL;
    lexer->cursor++;
    return VEC_GET(lexer->tokens, lexer->cursor - 1, token_t *);
}
