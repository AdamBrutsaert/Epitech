/*
** EPITECH PROJECT, 2023
** builtin_exit.c
** File description:
** builtin_exit.c
*/

#include "shell/builtins.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

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

static bool process(shell_t *shell, char **arguments, size_t length)
{
    if (length > 2) {
        fprintf(stderr, "exit: Expression Syntax.\n");
        shell_set_status(shell, 1);
        return false;
    }
    if (length == 2) {
        if (!is_int(arguments[1])) {
            fprintf(stderr, "exit: Expression Syntax.\n");
            shell_set_status(shell, 1);
            return false;
        }
        shell_set_status(shell, atoi(arguments[1]));
    } else {
        shell_set_status(shell, 0);
    }
    return true;
}

void builtin_exit(shell_t *shell, char **arguments)
{
    size_t length = 0;

    while (arguments[length] != NULL)
        length++;
    if (!process(shell, arguments, length))
        return;
    if (isatty(STDIN_FILENO))
        fprintf(stderr, "exit\n");
    shell_exit(shell);
}
