/*
** EPITECH PROJECT, 2023
** builtin_setenv.c
** File description:
** builtin_setenv.c
*/

#include "shell/builtins.h"
#include "my/memory.h"

#include <stdio.h>
#include <string.h>

bool check_name(shell_t *shell, char const *name)
{
    if (!((name[0] >= 'a' && name[0] <= 'z')
        || (name[0] >= 'A' && name[0] <= 'Z')
        || name[0] == '_')) {
        fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
        shell_set_status(shell, 1);
        return false;
    }
    for (; *name != '\0'; name++) {
        if (!((*name >= 'a' && *name <= 'z')
        || (*name >= 'A' && *name <= 'Z')
        || (*name >= '0' && *name <= '9') || *name == '_')) {
            fprintf(stderr, "setenv: Variable name must contain alphanumeric"
                " characters.\n");
            shell_set_status(shell, 1);
            return false;
        }
    }
    return true;
}

void builtin_setenv(shell_t *shell, char **arguments)
{
    size_t length = my_array_length(arguments);

    if (length == 1)
        return builtin_env(shell, arguments);
    if (length == 2) {
        if (check_name(shell, arguments[1])) {
            shell_set_env_var(shell, arguments[1], "");
            shell_set_status(shell, 0);
        }
        return;
    }
    if (length == 3) {
        if (check_name(shell, arguments[1])) {
            shell_set_env_var(shell, arguments[1], arguments[2]);
            shell_set_status(shell, 0);
        }
        return;
    }
    fprintf(stderr, "setenv: Too many arguments.\n");
    shell_set_status(shell, 1);
}
