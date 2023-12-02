/*
** EPITECH PROJECT, 2023
** builtin_execute.c
** File description:
** builtin_execute.c
*/

#include "shell/builtins.h"

#include <string.h>

void builtin_execute(shell_t *shell, char **arguments)
{
    if (!strcmp(arguments[0], "env"))
        builtin_env(shell, arguments);
    if (!strcmp(arguments[0], "setenv"))
        builtin_setenv(shell, arguments);
    if (!strcmp(arguments[0], "unsetenv"))
        builtin_unsetenv(shell, arguments);
    if (!strcmp(arguments[0], "cd"))
        builtin_cd(shell, arguments);
    if (!strcmp(arguments[0], "exit"))
        builtin_exit(shell, arguments);
    if (!strcmp(arguments[0], "alias"))
        builtin_alias(shell, arguments);
    if (!strcmp(arguments[0], "unalias"))
        builtin_unalias(shell, arguments);
    if (!strcmp(arguments[0], "history"))
        builtin_history(shell);
    if (!strcmp(arguments[0], "where"))
        builtin_where(shell, arguments);
    if (!strcmp(arguments[0], "which"))
        builtin_which(shell, arguments);
}
