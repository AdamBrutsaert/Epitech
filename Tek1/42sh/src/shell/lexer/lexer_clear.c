/*
** EPITECH PROJECT, 2023
** lexer_clear.c
** File description:
** lexer_clear.c
*/

#include "shell/lexer_impl.h"

void lexer_clear(lexer_t *lexer)
{
    vec_clear_and_delete(lexer->tokens, (deleter_t)token_delete);
    lexer->cursor = 0;
}
