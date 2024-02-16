/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** builtin_alias
*/

#include "shell.h"
#include "shell/builtins.h"
#include "shell/alias.h"
#include "my/memory.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void print_alias_values(char **values)
{
    for (int i = 0; values[i] != NULL; i++)
        printf("%s%s", values[i], (values[i + 1] != NULL) ? " " : "");
    printf("\n");
}

static void print_full_alias(shell_t *shell)
{
    for (alias_t *alias = shell_get_aliases(shell);
            alias != NULL; alias = alias_get_next(alias)) {
        printf("%s\t", alias_get_name(alias));
        print_alias_values(alias_get_values(alias));
    }
}

static void print_matching_alias(shell_t *shell, char *name)
{
    for (alias_t *alias = shell_get_aliases(shell);
            alias != NULL; alias = alias_get_next(alias))
        if (!strcmp(alias_get_name(alias), name))
            print_alias_values(alias_get_values(alias));
}

static bool check_for_dangerous_aliases(shell_t *shell, char **arguments)
{
    if (!strcmp(arguments[1], "alias") || !strcmp(arguments[1], "unalias")) {
        fprintf(stderr, "%s: Too dangerous to alias that.\n", arguments[1]);
        shell_set_status(shell, 1);
        return true;
    }
    return false;
}

void builtin_alias(shell_t *shell, char **arguments)
{
    if (arguments[1] == NULL) {
        print_full_alias(shell);
        shell_set_status(shell, 0);
        return;
    }
    if (arguments[2] == NULL) {
        print_matching_alias(shell, arguments[1]);
        shell_set_status(shell, 0);
        return;
    }
    if (check_for_dangerous_aliases(shell, arguments))
        return;
    shell_set_alias(shell, arguments);
    shell_set_status(shell, 0);
}
