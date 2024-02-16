/*
** EPITECH PROJECT, 2023
** lexer_peek.c
** File description:
** lexer_peek.c
*/

#include "shell/lexer.h"

token_t *lexer_peek(lexer_t *lexer)
{
    if (lexer->current >= lexer->length)
        return NULL;
    return &lexer->tokens[lexer->current];
}
