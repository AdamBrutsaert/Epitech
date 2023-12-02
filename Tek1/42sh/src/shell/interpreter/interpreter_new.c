/*
** EPITECH PROJECT, 2023
** interpreter_new.c
** File description:
** interpreter_new.c
*/

#include "shell/interpreter_impl.h"

#include <stdlib.h>

interpreter_t *interpreter_new(void)
{
    interpreter_t *interpreter = malloc(sizeof(interpreter_t));

    if (interpreter == NULL)
        return NULL;
    interpreter->processes = vec_new(sizeof(pid_t));
    interpreter->pipes = vec_new(sizeof(int));
    if (interpreter->processes == NULL || interpreter->pipes == NULL) {
        interpreter_delete(interpreter);
        return NULL;
    }
    interpreter->stdin_copy = -1;
    interpreter->stdout_copy = -1;
    return interpreter;
}
