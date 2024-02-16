/*
** EPITECH PROJECT, 2023
** lexer_peek.c
** File description:
** lexer_peek.c
*/

#include "asm/lexer_impl.h"

token_t *lexer_peek(lexer_t *lexer, size_t offset)
{
    return vec_get(lexer->tokens, lexer->cursor + offset);
}
