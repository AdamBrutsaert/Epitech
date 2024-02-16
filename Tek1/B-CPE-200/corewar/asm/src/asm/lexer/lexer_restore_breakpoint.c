/*
** EPITECH PROJECT, 2023
** lexer_restore_breakpoint.c
** File description:
** lexer_restore_breakpoint.c
*/

#include "asm/lexer_impl.h"

void lexer_restore_breakpoint(lexer_t *lexer, breakpoint_t breakpoint)
{
    while (VEC_LEN(lexer->tokens) > breakpoint)
        vec_pop(lexer->tokens);
}
