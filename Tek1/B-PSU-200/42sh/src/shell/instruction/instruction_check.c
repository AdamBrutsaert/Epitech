/*
** EPITECH PROJECT, 2023
** instruction_check.c
** File description:
** instruction_check.c
*/

#include "shell/instruction_impl.h"

#include <stdio.h>

static bool check(
    redirection_type_t type,
    bool *redirect_in,
    bool *redirect_out
)
{
    if ((type == REDIRECTION_INPUT && *redirect_in)
        || (type == REDIRECTION_HERE_DOCUMENT && *redirect_in)) {
        fprintf(stderr, "Ambiguous input redirect.\n");
        return false;
    }
    if ((type == REDIRECTION_OUTPUT && *redirect_out)
        || (type == REDIRECTION_APPEND && *redirect_out)) {
        fprintf(stderr, "Ambiguous output redirect.\n");
        return false;
    }
    if (type == REDIRECTION_INPUT || type == REDIRECTION_HERE_DOCUMENT)
        *redirect_in = true;
    if (type == REDIRECTION_OUTPUT || type == REDIRECTION_APPEND)
        *redirect_out = true;
    return true;
}

bool instruction_check(instruction_t *instruction)
{
    bool redirect_in = false;
    bool redirect_out = false;
    redirection_t *redirect;

    if (VEC_LEN(instruction->arguments) == 0
        && VEC_LEN(instruction->redirections) > 0) {
        fprintf(stderr, "Invalid null command.\n");
    }
    for (size_t i = 0; i < VEC_LEN(instruction->redirections); i++) {
        redirect = VEC_GET(instruction->redirections, i, redirection_t *);
        if (!check(redirection_get_type(redirect), &redirect_in, &redirect_out))
            return false;
    }
    return true;
}
