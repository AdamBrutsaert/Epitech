/*
** EPITECH PROJECT, 2023
** builtin_env.c
** File description:
** builtin_env.c
*/

#include "shell/builtins.h"
#include "my/stdio.h"

void builtin_env(
    interpreter_t *interpreter,
    __attribute__((unused)) char **arguments
)
{
    for (char **env = interpreter->env; *env != NULL; env++) {
        my_puts(*env);
        my_puts("\n");
    }
    interpreter_set_status(interpreter, 0);
}
