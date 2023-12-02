/*
** EPITECH PROJECT, 2023
** lexer_delete.c
** File description:
** lexer_delete.c
*/

#include "asm/lexer_impl.h"
#include "my/memory.h"

void lexer_delete(lexer_t *lexer)
{
    vec_delete(lexer->tokens);
    arena_delete(lexer->scratch);
    arena_delete(lexer->arena);
    my_free(lexer);
}
