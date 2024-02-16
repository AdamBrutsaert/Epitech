/*
** EPITECH PROJECT, 2023
** shell_get_env.c
** File description:
** shell_get_env.c
*/

#include "shell_impl.h"

char **shell_get_env(shell_t *shell)
{
    return shell->env;
}
