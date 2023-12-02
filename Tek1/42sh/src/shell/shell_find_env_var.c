/*
** EPITECH PROJECT, 2023
** shell_find_env_var.c
** File description:
** shell_find_env_var.c
*/

#include "shell_impl.h"

#include <string.h>

size_t shell_find_env_var(shell_t *shell, const char *key)
{
    size_t length = strlen(key);
    size_t index = 0;

    for (; shell->env[index] != NULL; index++) {
        if (!strncmp(key, shell->env[index], length)
            && shell->env[index][length] == '=')
            break;
    }
    return index;
}
