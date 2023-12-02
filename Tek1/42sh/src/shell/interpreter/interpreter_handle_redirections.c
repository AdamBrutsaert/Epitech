/*
** EPITECH PROJECT, 2023
** interpreter_handle_redirections.c
** File description:
** interpreter_handle_redirections.c
*/

#include "shell/interpreter_impl.h"

static bool handle_redirection(
    interpreter_t *interpreter,
    redirection_t *redirection
)
{
    if (redirection_get_type(redirection) == REDIRECTION_INPUT)
        return interpreter_handle_input(interpreter, redirection);
    if (redirection_get_type(redirection) == REDIRECTION_OUTPUT)
        return interpreter_handle_output(interpreter, redirection);
    if (redirection_get_type(redirection) == REDIRECTION_APPEND)
        return interpreter_handle_append(interpreter, redirection);
    if (redirection_get_type(redirection) == REDIRECTION_HERE_DOCUMENT)
        return interpreter_handle_here_document(interpreter, redirection);
    return false;
}

bool interpreter_handle_redirections(interpreter_t *interpreter)
{
    vec_t *redirections = instruction_get_redirections(
        interpreter->instruction);
    redirection_t *redirection;

    for (size_t i = 0; i < VEC_LEN(redirections); i++) {
        redirection = VEC_GET(redirections, i, redirection_t *);
        if (!handle_redirection(interpreter, redirection))
            return false;
    }
    return true;
}
