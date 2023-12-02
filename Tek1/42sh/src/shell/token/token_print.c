/*
** EPITECH PROJECT, 2023
** token_print.c
** File description:
** token_print.c
*/

#include "shell/token_impl.h"

#include <stdio.h>

void token_print(token_t *token)
{
    if (token->type == TOKEN_NEWLINE) {
        printf("[%d] \\n\n", token->type);
    } else {
        printf("[%d] %s\n", token->type, token->value);
    }
}
