/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtin_unalias
*/

#include "shell.h"
#include "shell/builtins.h"
#include "shell/alias.h"

#include <stdio.h>
#include <string.h>

void builtin_unalias(shell_t *shell, char **arguments)
{
    if (arguments[1] == NULL) {
        fprintf(stderr, "unalias: Too few arguments.\n");
        shell_set_status(shell, 1);
        return;
    }
    for (int i = 1; arguments[i] != NULL; i++)
        shell_remove_alias(shell, arguments[i]);
    shell_set_status(shell, 0);
}
