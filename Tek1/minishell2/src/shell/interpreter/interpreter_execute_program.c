/*
** EPITECH PROJECT, 2023
** interpreter_execute_program.c
** File description:
** interpreter_execute_program.c
*/

#include "shell/interpreter.h"
#include "my/stdio.h"

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

void interpreter_execute_program(
    interpreter_t *interpreter,
    instruction_t *instruction
)
{
    char *program = interpreter_get_program_path(
        interpreter,
        instruction->arguments[0]
    );

    if (program == NULL)
        exit(1);
    if (execve(program, instruction->arguments, interpreter->env) == -1) {
        if (errno == ENOEXEC) {
            my_eputs(instruction->arguments[0]);
            my_eputs(": Exec format error. Wrong Architecture.\n");
        }
    }
}
