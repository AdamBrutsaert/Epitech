/*
** EPITECH PROJECT, 2023
** token_debug.c
** File description:
** token_debug.c
*/

#include "shell/token.h"
#include "my/stdio.h"

static void print_type(token_t *token)
{
    if (token->type == TOKEN_LEFT_CHEVRON)
        my_puts("LEFT_CHEVRON         ");
    if (token->type == TOKEN_DOUBLE_LEFT_CHEVRON)
        my_puts("DOUBLE_LEFT_CHEVRON  ");
    if (token->type == TOKEN_RIGHT_CHEVRON)
        my_puts("RIGHT_CHEVRON        ");
    if (token->type == TOKEN_DOUBLE_RIGHT_CHEVRON)
        my_puts("DOUBLE_RIGHT_CHEVRON ");
    if (token->type == TOKEN_PIPE)
        my_puts("PIPE                 ");
    if (token->type == TOKEN_SEMICOLON)
        my_puts("SEMICOLON            ");
    if (token->type == TOKEN_NEWLINE)
        my_puts("NEWLINE              ");
    if (token->type == TOKEN_STRING)
        my_puts("STRING               ");
    if (token->type == TOKEN_END)
        my_puts("END                  ");
}

static void print_value(token_t *token)
{
    if (token->type == TOKEN_NEWLINE) {
        my_puts("\\n");
    }
    if (token->type != TOKEN_NEWLINE && token->type != TOKEN_END) {
        my_puts(token->value);
    }
    my_putc('\n');
}

void token_debug(token_t *token)
{
    print_type(token);
    print_value(token);
}
