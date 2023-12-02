/*
** EPITECH PROJECT, 2023
** lexer_reset.c
** File description:
** lexer_reset.c
*/

#include "shell/lexer.h"

#include <stdlib.h>

void lexer_reset(lexer_t *lexer)
{
    for (size_t i = 0; i < lexer->length; i++)
        free(lexer->tokens[i].value);
    free(lexer->tokens);
    lexer->tokens = NULL;
    lexer->length = 0;
    lexer->capacity = 0;
    lexer->current = 0;
}
