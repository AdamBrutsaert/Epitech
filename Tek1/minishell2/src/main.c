/*
** EPITECH PROJECT, 2023
** main.c
** File description:
** main.c
*/

#include "shell/interpreter.h"

int main(int argc, char **argv, char **envp)
{
    interpreter_t *interpreter = interpreter_create(argc, argv, envp);
    int status;

    if (!interpreter)
        return 84;
    status = interpreter_run(interpreter);
    interpreter_destroy(interpreter);
    return status;
}
