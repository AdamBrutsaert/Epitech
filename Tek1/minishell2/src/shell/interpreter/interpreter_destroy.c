/*
** EPITECH PROJECT, 2023
** interpreter_destroy.c
** File description:
** interpreter_destroy.c
*/

#include "shell/interpreter.h"

#include <stdlib.h>

void interpreter_destroy(interpreter_t *interpreter)
{
    if (interpreter == NULL)
        return;
    parser_destroy(interpreter->parser);
    lexer_destroy(interpreter->lexer);
    reader_destroy(interpreter->reader);
    for (size_t i = 0; interpreter->env[i]; i++)
        free(interpreter->env[i]);
    free(interpreter->env);
    free(interpreter);
}
