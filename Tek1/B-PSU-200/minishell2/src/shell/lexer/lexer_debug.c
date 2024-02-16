/*
** EPITECH PROJECT, 2023
** lexer_debug.c
** File description:
** lexer_debug.c
*/

#include "shell/lexer.h"
#include "my/stdio.h"

void lexer_debug(lexer_t *lexer)
{
    for (size_t i = 0; i < lexer->length; i++)
        token_debug(&lexer->tokens[i]);
}
