/*
** EPITECH PROJECT, 2023
** lexer_destroy.c
** File description:
** lexer_destroy.c
*/

#include "shell/lexer.h"

#include <stdlib.h>

void lexer_destroy(lexer_t *lexer)
{
    if (lexer == NULL)
        return;
    lexer_reset(lexer);
    free(lexer);
}
