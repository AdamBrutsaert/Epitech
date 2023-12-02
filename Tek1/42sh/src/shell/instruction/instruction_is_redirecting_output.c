/*
** EPITECH PROJECT, 2023
** instruction_is_redirecting_output.c
** File description:
** instruction_is_redirecting_output.c
*/

#include "shell/instruction_impl.h"

bool instruction_is_redirecting_output(instruction_t *instruction)
{
    redirection_t *redirect;

    for (size_t i = 0; i < VEC_LEN(instruction->redirections); i++) {
        redirect = VEC_GET(instruction->redirections, i, redirection_t *);
        if (redirection_get_type(redirect) == REDIRECTION_OUTPUT
            || redirection_get_type(redirect) == REDIRECTION_APPEND)
            return true;
    }
    return false;
}
