/*
** EPITECH PROJECT, 2023
** lexer_create_breakpoint.c
** File description:
** lexer_create_breakpoint.c
*/

#include "asm/lexer_impl.h"

breakpoint_t lexer_create_breakpoint(lexer_t *lexer)
{
    return VEC_LEN(lexer->tokens);
}
