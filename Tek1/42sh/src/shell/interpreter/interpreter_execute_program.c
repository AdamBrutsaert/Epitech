/*
** EPITECH PROJECT, 2023
** interpreter_execute_program.c
** File description:
** interpreter_execute_program.c
*/

#include "shell/interpreter_impl.h"
#include "shell.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void interpreter_execute_program(interpreter_t *interpreter)
{
    char **arguments = instruction_get_arguments(interpreter->instruction);
    char *program = shell_find_program(interpreter->shell, arguments[0]);

    if (program == NULL)
        exit(1);
    if (execve(program, arguments, shell_get_env(interpreter->shell)) == -1) {
        if (errno == ENOEXEC)
            fprintf(stderr, "%s: Exec format error. Wrong Architecture.\n",
                program);
        exit(1);
    }
}
