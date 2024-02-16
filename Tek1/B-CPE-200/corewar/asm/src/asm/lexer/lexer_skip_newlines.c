/*
** EPITECH PROJECT, 2023
** lexer_skip_newlines.c
** File description:
** lexer_skip_newlines.c
*/

#include "asm/lexer_impl.h"

void lexer_skip_newlines(lexer_t *lexer)
{
    token_type_t type = lexer_peek_type(lexer, 0);

    while (type == TOKEN_NEWLINE) {
        lexer_next(lexer);
        type = lexer_peek_type(lexer, 0);
    }
}
