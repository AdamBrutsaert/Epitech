/*
** EPITECH PROJECT, 2023
** instruction_is_redirecting_input.c
** File description:
** instruction_is_redirecting_input.c
*/

#include "shell/instruction_impl.h"

bool instruction_is_redirecting_input(instruction_t *instruction)
{
    redirection_t *redirect;

    for (size_t i = 0; i < VEC_LEN(instruction->redirections); i++) {
        redirect = VEC_GET(instruction->redirections, i, redirection_t *);
        if (redirection_get_type(redirect) == REDIRECTION_HERE_DOCUMENT
            || redirection_get_type(redirect) == REDIRECTION_INPUT)
            return true;
    }
    return false;
}
