/*
** EPITECH PROJECT, 2023
** lexer_next.c
** File description:
** lexer_next.c
*/

#include "shell/lexer.h"

token_t *lexer_next(lexer_t *lexer)
{
    if (lexer->current >= lexer->length)
        return NULL;
    lexer->current++;
    return &lexer->tokens[lexer->current - 1];
}
