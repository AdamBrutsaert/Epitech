/*
** EPITECH PROJECT, 2023
** lexer_delete.c
** File description:
** lexer_delete.c
*/

#include "shell/lexer_impl.h"

#include <stdlib.h>

void lexer_delete(lexer_t *lexer)
{
    if (lexer == NULL)
        return;
    vec_clear_and_delete(lexer->tokens, (deleter_t)token_delete);
    vec_delete(lexer->tokens);
    free(lexer);
}
