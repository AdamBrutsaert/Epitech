/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell_get_aliases
*/

#include "shell_impl.h"

alias_t *shell_get_aliases(shell_t *shell)
{
    return shell->aliases;
}
