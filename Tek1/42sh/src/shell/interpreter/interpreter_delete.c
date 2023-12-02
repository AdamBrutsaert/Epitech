/*
** EPITECH PROJECT, 2023
** interpreter_delete.c
** File description:
** interpreter_delete.c
*/

#include "shell/interpreter_impl.h"

#include <stdlib.h>

void interpreter_delete(interpreter_t *interpreter)
{
    if (interpreter == NULL)
        return;
    vec_delete(interpreter->processes);
    vec_delete(interpreter->pipes);
    free(interpreter);
}
