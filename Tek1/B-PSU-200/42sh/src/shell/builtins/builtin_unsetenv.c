/*
** EPITECH PROJECT, 2023
** builtin_unsetenv.c
** File description:
** builtin_unsetenv.c
*/

#include "shell/builtins.h"
#include "my/memory.h"

#include <stdio.h>
#include <string.h>

void builtin_unsetenv(shell_t *shell, char **arguments)
{
    size_t length = my_array_length(arguments);
    if (length == 1) {
        fprintf(stderr, "unsetenv: Too few arguments.\n");
        shell_set_status(shell, 1);
    } else {
        for (size_t i = 1; arguments[i] != NULL; i++)
            shell_unset_env_var(shell, arguments[i]);
        shell_set_status(shell, 0);
    }
}
