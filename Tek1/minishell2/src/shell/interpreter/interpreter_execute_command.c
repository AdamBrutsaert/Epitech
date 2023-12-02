/*
** EPITECH PROJECT, 2023
** interpreter_execute_command.c
** File description:
** interpreter_execute_command.c
*/

#include "shell/interpreter.h"

void interpreter_execute_command(
    interpreter_t *interpreter,
    command_t *command
)
{
    if (command_is_empty(command))
        return;
    for (size_t i = 0; i < command->length; i++)
        interpreter_execute_pipeline(interpreter, command->pipelines[i]);
}
