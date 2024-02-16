/*
** EPITECH PROJECT, 2023
** compiler_error_token.c
** File description:
** compiler_error_token.c
*/

#include "asm/compiler_impl.h"
#include "my/stdio.h"

void compiler_error_token(compiler_t *compiler, token_t *token)
{
    my_eputcs("error: compiler: ");
    my_eputcs(compiler->path);
    if (token == NULL || token->type == TOKEN_EOF) {
        my_eputcs(": unexpected end of file.\n");
    } else {
        my_eputcs(": line ");
        my_eputu(token->line);
        my_eputcs(": unexpected token '");
        my_eputs(token->value);
        my_eputcs("'.\n");
    }
}
