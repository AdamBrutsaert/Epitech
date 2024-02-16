/*
** EPITECH PROJECT, 2023
** instruction_count_redirect_out.c
** File description:
** instruction_count_redirect_out.c
*/

#include "shell/instruction.h"

size_t instruction_count_redirect_out(instruction_t *instruction)
{
    size_t count = 0;

    for (size_t i = 0; i < instruction->redirects_length; i++) {
        if (instruction->redirects[i].type == REDIRECT_OUTPUT
            || instruction->redirects[i].type == REDIRECT_APPEND)
            count++;
    }
    return count;
}
