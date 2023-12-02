/*
** EPITECH PROJECT, 2023
** lexer_create.c
** File description:
** lexer_create.c
*/

#include "shell/lexer.h"
#include "my/memory.h"

#include <stdlib.h>

lexer_t *lexer_create(reader_t *reader)
{
    lexer_t *lexer = malloc(sizeof(lexer_t));

    if (lexer == NULL)
        return NULL;
    my_memset(lexer, 0, sizeof(lexer_t));
    lexer->reader = reader;
    return lexer;
}
