/*
** EPITECH PROJECT, 2023
** lexer_push.c
** File description:
** lexer_push.c
*/

#include "shell/lexer.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(lexer_t *lexer)
{
    size_t capacity = lexer->capacity * 2 + !lexer->capacity;
    token_t *tokens = malloc(capacity * sizeof(token_t));

    if (!tokens)
        return false;
    my_memmove(tokens, lexer->tokens, lexer->length * sizeof(token_t));
    free(lexer->tokens);
    lexer->tokens = tokens;
    lexer->capacity = capacity;
    return true;
}

bool lexer_push(lexer_t *lexer, token_type_t type, char *value)
{
    if (lexer->length == lexer->capacity && !grow(lexer))
        return false;
    lexer->tokens[lexer->length].type = type;
    lexer->tokens[lexer->length].value = value;
    lexer->length++;
    return true;
}
