/*
** EPITECH PROJECT, 2023
** interpreter_set_status.c
** File description:
** interpreter_set_status.c
*/

#include "shell/interpreter.h"

void interpreter_set_status(
    interpreter_t *interpreter,
    int status
)
{
    if ((interpreter->exit && status != 0) || !interpreter->exit)
        interpreter->status = status;
}
