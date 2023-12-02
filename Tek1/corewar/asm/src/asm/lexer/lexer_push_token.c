/*
** EPITECH PROJECT, 2023
** lexer_push_token.c
** File description:
** lexer_push_token.c
*/

#include "asm/lexer_impl.h"

void lexer_push_token(
    lexer_t *lexer,
    reader_t *reader,
    token_type_t type,
    string_t *string
)
{
    token_t token;

    token.line = reader_get_line_number(reader) - (type == TOKEN_NEWLINE);
    token.type = type;
    token.value = string_duplicate(lexer->arena, string);
    vec_push(lexer->tokens, &token);
}
