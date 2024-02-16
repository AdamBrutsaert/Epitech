/*
** EPITECH PROJECT, 2023
** builtin_exit.c
** File description:
** builtin_exit.c
*/

#include "shell.h"
#include "my/string.h"
#include "my/stdio.h"

static bool is_int(char const *string)
{
    if (*string == '-')
        string++;
    for (; *string; string++) {
        if (*string < '0' || *string > '9')
            return false;
    }
    return true;
}

static int arg_to_int(char const *string)
{
    int nb = 0;
    int sign = 1;

    if (*string == '-') {
        string++;
        sign = -1;
    }
    for (; *string; string++)
        nb = nb * 10 + sign * (*string - '0');
    return nb;
}

void builtin_exit(shell_t *shell, char **arguments)
{
    uint64_t length = my_strarrlen(arguments);

    if (length > 2) {
        my_eputs("exit: Expression Syntax.\n");
        shell->status = 1;
        return;
    }
    if (length == 2) {
        if (!is_int(arguments[1])) {
            my_eputs("exit: Expression Syntax.\n");
            shell->status = 1;
            return;
        }
        shell->status = arg_to_int(arguments[1]);
    } else {
        shell->status = 0;
    }
    shell->exit = true;
}
