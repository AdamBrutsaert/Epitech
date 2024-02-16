/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell_remove_alias
*/

#include "shell_impl.h"
#include "shell/alias_impl.h"

#include <string.h>

void remove_alias(shell_t *shell, alias_t *prev, alias_t *alias)
{
    if (prev == NULL)
        shell->aliases = alias_get_next(alias);
    else
        prev->next = alias_get_next(alias);
    alias_destroy(alias);
}

void shell_remove_alias(shell_t *shell, const char *name)
{
    alias_t *prev = NULL;
    alias_t *alias = shell_get_aliases(shell);

    while (alias != NULL) {
        if (!strcmp(alias_get_name(alias), name)) {
            remove_alias(shell, prev, alias);
            return;
        }
        prev = alias;
        alias = alias_get_next(alias);
    }
}
