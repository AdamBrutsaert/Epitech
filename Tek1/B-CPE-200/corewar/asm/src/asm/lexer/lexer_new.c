/*
** EPITECH PROJECT, 2023
** lexer_new.c
** File description:
** lexer_new.c
*/

#include "asm/lexer_impl.h"
#include "my/memory.h"

lexer_t *lexer_new(void)
{
    lexer_t *lexer = my_calloc(sizeof(lexer_t));

    lexer->tokens = vec_new(sizeof(token_t));
    lexer->scratch = arena_new();
    lexer->arena = arena_new();
    return lexer;
}
