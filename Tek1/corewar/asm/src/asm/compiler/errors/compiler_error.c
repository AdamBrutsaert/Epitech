/*
** EPITECH PROJECT, 2023
** compiler_error.c
** File description:
** compiler_error.c
*/

#include "asm/compiler_impl.h"
#include "my/stdio.h"

void compiler_error(compiler_t *compiler, token_t *token, const char *message)
{
    my_eputcs("error: compiler: ");
    my_eputcs(compiler->path);
    if (token != NULL) {
        my_eputcs(": line ");
        my_eputu(token->line);
    }
    my_eputcs(": ");
    my_eputcs(message);
    my_eputcs(".\n");
}
