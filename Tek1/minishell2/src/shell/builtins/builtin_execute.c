/*
** EPITECH PROJECT, 2023
** builtin_execute.c
** File description:
** builtin_execute.c
*/

#include "shell/builtins.h"
#include "my/string.h"

void builtin_execute(interpreter_t *interpreter, char **arguments)
{
    if (!my_strcmp(arguments[0], "env"))
        builtin_env(interpreter, arguments);
    if (!my_strcmp(arguments[0], "setenv"))
        builtin_setenv(interpreter, arguments);
    if (!my_strcmp(arguments[0], "unsetenv"))
        builtin_unsetenv(interpreter, arguments);
    if (!my_strcmp(arguments[0], "cd"))
        builtin_cd(interpreter, arguments);
    if (!my_strcmp(arguments[0], "exit"))
        builtin_exit(interpreter, arguments);
}
