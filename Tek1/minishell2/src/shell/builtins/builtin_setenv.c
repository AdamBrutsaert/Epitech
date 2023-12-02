/*
** EPITECH PROJECT, 2023
** builtin_setenv.c
** File description:
** builtin_setenv.c
*/

#include "shell/builtins.h"
#include "my/string.h"
#include "my/stdio.h"

bool check_name(interpreter_t *interpreter, char const *name)
{
    if (!((name[0] >= 'a' && name[0] <= 'z')
        || (name[0] >= 'A' && name[0] <= 'Z')
        || name[0] == '_')) {
        my_eputs("setenv: Variable name must begin with a letter.\n");
        interpreter_set_status(interpreter, 1);
        return false;
    }
    for (; *name != '\0'; name++) {
        if (!((*name >= 'a' && *name <= 'z')
        || (*name >= 'A' && *name <= 'Z')
        || (*name >= '0' && *name <= '9') || *name == '_')) {
            my_eputs("setenv: Variable name must contain alphanumeric"
                " characters.\n");
            interpreter_set_status(interpreter, 1);
            return false;
        }
    }
    return true;
}

static size_t get_args_length(char **arguments)
{
    size_t length = 0;

    while (arguments[length] != NULL)
        length++;
    return length;
}

void builtin_setenv(interpreter_t *interpreter, char **arguments)
{
    size_t length = get_args_length(arguments);

    if (length == 1)
        return builtin_env(interpreter, arguments);
    if (length == 2) {
        if (check_name(interpreter, arguments[1])) {
            interpreter_set_env(interpreter, arguments[1], "");
            interpreter_set_status(interpreter, 0);
        }
        return;
    }
    if (length == 3) {
        if (check_name(interpreter, arguments[1])) {
            interpreter_set_env(interpreter, arguments[1], arguments[2]);
            interpreter_set_status(interpreter, 0);
        }
        return;
    }
    my_eputs("setenv: Too many arguments.\n");
    interpreter_set_status(interpreter, 1);
}
