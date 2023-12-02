/*
** EPITECH PROJECT, 2023
** lexer_print.c
** File description:
** lexer_print.c
*/

#include "shell/lexer_impl.h"

void lexer_print(lexer_t *lexer)
{
    for (size_t i = 0; i < VEC_LEN(lexer->tokens); i++)
        token_print(VEC_GET(lexer->tokens, i, token_t *));
}
