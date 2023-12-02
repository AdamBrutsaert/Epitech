/*
** EPITECH PROJECT, 2023
** lexer_debug.c
** File description:
** lexer_debug.c
*/

#include "asm/lexer_impl.h"
#include "asm/lexer_glob.h"
#include "my/stdio.h"

void lexer_debug(lexer_t *lexer)
{
    token_t *token = NULL;

    for (size_t i = 0; i < VEC_LEN(lexer->tokens); i++) {
        token = vec_get(lexer->tokens, i);
        my_putu(token->line);
        my_putc('\t');
        my_putcs(TOKEN_NAMES[token->type]);
        my_putcs("\t>>");
        if (token->type == TOKEN_NEWLINE) {
            my_putcs("\\n");
        } else {
            my_puts(token->value);
        }
        my_putcs("<<\n");
    }
}
