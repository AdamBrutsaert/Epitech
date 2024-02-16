/*
** EPITECH PROJECT, 2023
** compiler_error_command.c
** File description:
** compiler_error_command.c
*/

#include "asm/compiler_impl.h"
#include "my/stdio.h"

void compiler_error_command(compiler_t *compiler, token_t *token)
{
    my_eputcs("error: compiler: ");
    my_eputcs(compiler->path);
    my_eputcs(": line ");
    my_eputu(token->line);
    my_eputcs(": unexpected command '");
    my_eputs(token->value);
    my_eputcs("'.\n");
}
