/*
** EPITECH PROJECT, 2023
** lexer_new.c
** File description:
** lexer_new.c
*/

#include "shell/lexer_impl.h"

#include <stdlib.h>

lexer_t *lexer_new(void)
{
    lexer_t *lexer = calloc(1, sizeof(lexer_t));

    if (lexer == NULL)
        return NULL;
    lexer->tokens = vec_new(sizeof(token_t *));
    if (lexer->tokens == NULL) {
        lexer_delete(lexer);
        return NULL;
    }
    return lexer;
}
