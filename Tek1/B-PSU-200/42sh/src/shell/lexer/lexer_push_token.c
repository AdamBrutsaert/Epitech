/*
** EPITECH PROJECT, 2023
** lexer_push_token.c
** File description:
** lexer_push_token.c
*/

#include "shell/lexer_impl.h"

#include <stdlib.h>

bool lexer_push_token(
    lexer_t *lexer,
    reader_t *reader,
    token_type_t type,
    size_t length
)
{
    char *value = reader_dup_previous(reader, length);
    token_t *token;

    if (value == NULL)
        return false;
    token = token_new(type, value);
    if (token == NULL) {
        free(value);
        return false;
    }
    if (!VEC_PUSH(lexer->tokens, token)) {
        token_delete(token);
        return false;
    }
    return true;
}
