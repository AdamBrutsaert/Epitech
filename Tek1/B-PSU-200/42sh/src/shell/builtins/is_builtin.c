/*
** EPITECH PROJECT, 2023
** is_builtin.c
** File description:
** is_builtin.c
*/

#include "shell/builtins.h"

#include <string.h>

bool is_builtin(const char *program)
{
    return !strcmp(program, "env")
        || !strcmp(program, "setenv")
        || !strcmp(program, "unsetenv")
        || !strcmp(program, "cd")
        || !strcmp(program, "exit")
        || !strcmp(program, "alias")
        || !strcmp(program, "unalias")
        || !strcmp(program, "history")
        || !strcmp(program, "where")
        || !strcmp(program, "which");
}
