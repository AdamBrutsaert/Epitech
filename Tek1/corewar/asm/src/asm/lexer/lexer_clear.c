/*
** EPITECH PROJECT, 2023
** lexer_clear.c
** File description:
** lexer_clear.c
*/

#include "asm/lexer_impl.h"

void lexer_clear(lexer_t *lexer)
{
    vec_clear(lexer->tokens);
    arena_clear(lexer->scratch);
    arena_clear(lexer->arena);
    lexer->cursor = 0;
}
