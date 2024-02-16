/*
** EPITECH PROJECT, 2023
** shell_unset_env_var.c
** File description:
** shell_unset_env_var.c
*/

#include "shell_impl.h"

#include <stdlib.h>

void shell_unset_env_var(shell_t *shell, const char *key)
{
    size_t index = shell_find_env_var(shell, key);

    if (shell->env[index] == NULL)
        return;
    free(shell->env[index]);
    for (size_t i = index; shell->env[i] != NULL; i++)
        shell->env[i] = shell->env[i + 1];
}
