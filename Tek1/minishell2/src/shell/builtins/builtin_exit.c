/*
** EPITECH PROJECT, 2023
** builtin_exit.c
** File description:
** builtin_exit.c
*/

#include "shell/builtins.h"
#include "my/string.h"
#include "my/stdio.h"

#include <unistd.h>

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

static bool process(interpreter_t *interpreter, char **arguments, size_t length)
{
    if (length > 2) {
        my_eputs("exit: Expression Syntax.\n");
        interpreter_set_status(interpreter, 1);
        return false;
    }
    if (length == 2) {
        if (!is_int(arguments[1])) {
            my_eputs("exit: Expression Syntax.\n");
            interpreter_set_status(interpreter, 1);
            return false;
        }
        interpreter_set_status(interpreter, arg_to_int(arguments[1]));
    } else {
        interpreter_set_status(interpreter, 0);
    }
    return true;
}

void builtin_exit(interpreter_t *interpreter, char **arguments)
{
    size_t length = 0;

    while (arguments[length] != NULL)
        length++;
    if (!process(interpreter, arguments, length))
        return;
    if (isatty(STDIN_FILENO))
        my_eputs("exit\n");
    interpreter->exit = true;
}
