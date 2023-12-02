/*
** EPITECH PROJECT, 2023
** builtin_env.c
** File description:
** builtin_env.c
*/

#include "shell.h"
#include "my/stdio.h"

#include <stddef.h>

void builtin_env(shell_t *shell, __attribute__((unused)) char **arguments)
{
    for (char **env = shell->env; *env != NULL; env++) {
        my_puts(*env);
        my_puts("\n");
    }
    shell->status = 0;
}
