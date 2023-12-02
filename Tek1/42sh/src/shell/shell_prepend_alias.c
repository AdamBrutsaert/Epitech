/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell_prepend_alias
*/

#include "shell_impl.h"
#include "shell/alias_impl.h"

void shell_preprend_alias(shell_t *shell, alias_t *alias)
{
    alias->next = shell->aliases;
    shell->aliases = alias;
}
