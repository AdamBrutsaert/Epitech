/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** shell_set_alias
*/

#include "shell/alias_impl.h"
#include "shell.h"
#include <stdlib.h>
#include <string.h>

void shell_set_alias(shell_t *shell, char **arguments)
{
    alias_t *aliases = shell_get_aliases(shell);
    alias_t *alias = malloc(sizeof(alias_t));

    for (; aliases != NULL; aliases = alias_get_next(aliases))
        if (!strcmp(alias_get_name(aliases), arguments[1])) {
            alias_set_values(aliases, arguments, free);
            free(alias);
            return;
        }
    alias_set_name(alias, arguments[1]);
    alias_set_values(alias, arguments, calloc);
    shell_preprend_alias(shell, alias);
}
