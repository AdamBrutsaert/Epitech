/*
** EPITECH PROJECT, 2023
** builtin_unsetenv.c
** File description:
** builtin_unsetenv.c
*/

#include "shell/builtins.h"
#include "my/string.h"
#include "my/stdio.h"

void builtin_unsetenv(interpreter_t *interpreter, char **arguments)
{
    size_t length = 0;

    while (arguments[length] != NULL)
        length++;
    if (length == 1) {
        my_eputs("unsetenv: Too few arguments.\n");
        interpreter_set_status(interpreter, 1);
    } else {
        for (uint64_t i = 1; arguments[i] != NULL; i++)
            interpreter_unset_env(interpreter, arguments[i]);
        interpreter_set_status(interpreter, 0);
    }
}
