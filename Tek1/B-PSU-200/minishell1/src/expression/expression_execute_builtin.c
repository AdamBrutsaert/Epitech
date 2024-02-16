/*
** EPITECH PROJECT, 2023
** expression_execute_builtin.c
** File description:
** expression_execute_builtin.c
*/

#include "expression.h"
#include "builtins.h"
#include "my/string.h"

static bool expression_execute_builtin2(shell_t *shell, char **arguments)
{
    if (!my_strcmp(arguments[0], "cd")) {
        builtin_cd(shell, arguments);
        return true;
    }
    return false;
}

bool expression_execute_builtin(shell_t *shell, char **arguments)
{
    if (!my_strcmp(arguments[0], "env")) {
        builtin_env(shell, arguments);
        return true;
    }
    if (!my_strcmp(arguments[0], "exit")) {
        builtin_exit(shell, arguments);
        return true;
    }
    if (!my_strcmp(arguments[0], "setenv")) {
        builtin_setenv(shell, arguments);
        return true;
    }
    if (!my_strcmp(arguments[0], "unsetenv")) {
        builtin_unsetenv(shell, arguments);
        return true;
    }
    return expression_execute_builtin2(shell, arguments);
}
