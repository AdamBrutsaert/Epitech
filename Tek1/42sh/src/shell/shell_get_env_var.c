/*
** EPITECH PROJECT, 2023
** shell_get_env_var.c
** File description:
** shell_get_env_var.c
*/

#include "shell_impl.h"

#include <string.h>

char *shell_get_env_var(shell_t *shell, const char *key)
{
    size_t index = shell_find_env_var(shell, key);

    if (shell->env[index] == NULL)
        return NULL;
    return strdup(shell->env[index] + strlen(key) + 1);
}
