/*
** EPITECH PROJECT, 2023
** builtin_setenv.c
** File description:
** builtin_setenv.c
*/

#include "builtins.h"
#include "my/string.h"
#include "my/stdio.h"

bool check_name(shell_t *shell, char const *name)
{
    if (!((name[0] >= 'a' && name[0] <= 'z')
        || (name[0] >= 'A' && name[0] <= 'Z')
        || name[0] == '_')) {
        my_eputs("setenv: Variable name must begin with a letter.\n");
        shell->status = 1;
        return false;
    }
    for (; *name != '\0'; name++) {
        if (!((*name >= 'a' && *name <= 'z')
        || (*name >= 'A' && *name <= 'Z')
        || (*name >= '0' && *name <= '9') || *name == '_')) {
            my_eputs("setenv: Variable name must contain alphanumeric"
                " characters.\n");
            shell->status = 1;
            return false;
        }
    }
    return true;
}

void builtin_setenv(shell_t *shell, char **arguments)
{
    uint64_t length = my_strarrlen(arguments);

    if (length == 1)
        return builtin_env(shell, arguments);
    if (length == 2) {
        if (check_name(shell, arguments[1])) {
            shell_set(shell, arguments[1], "");
            shell->status = 0;
        }
        return;
    }
    if (length == 3) {
        if (check_name(shell, arguments[1])) {
            shell_set(shell, arguments[1], arguments[2]);
            shell->status = 0;
        }
        return;
    }
    my_eputs("setenv: Too many arguments.\n");
    shell->status = 1;
}
