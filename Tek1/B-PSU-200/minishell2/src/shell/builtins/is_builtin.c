/*
** EPITECH PROJECT, 2023
** is_builtin.c
** File description:
** is_builtin.c
*/

#include "shell/builtins.h"
#include "my/string.h"

bool is_builtin(const char *program)
{
    return !my_strcmp(program, "env")
        || !my_strcmp(program, "setenv")
        || !my_strcmp(program, "unsetenv")
        || !my_strcmp(program, "cd")
        || !my_strcmp(program, "exit");
}
