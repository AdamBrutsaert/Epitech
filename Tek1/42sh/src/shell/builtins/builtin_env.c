/*
** EPITECH PROJECT, 2023
** builtin_env.c
** File description:
** builtin_env.c
*/

#include "shell/builtins.h"

#include <stdio.h>

void builtin_env(shell_t *shell, __attribute__((unused)) char **arguments)
{
    for (char **env = shell_get_env(shell); *env != NULL; env++)
        printf("%s\n", *env);
    shell_set_status(shell, 0);
    fflush(stdout);
}
