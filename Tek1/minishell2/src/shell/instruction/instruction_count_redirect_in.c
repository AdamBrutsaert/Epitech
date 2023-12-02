/*
** EPITECH PROJECT, 2023
** instruction_count_redirect_in.c
** File description:
** instruction_count_redirect_in.c
*/

#include "shell/instruction.h"

size_t instruction_count_redirect_in(instruction_t *instruction)
{
    size_t count = 0;

    for (size_t i = 0; i < instruction->redirects_length; i++) {
        if (instruction->redirects[i].type == REDIRECT_HERE_DOCUMENT
            || instruction->redirects[i].type == REDIRECT_INPUT)
            count++;
    }
    return count;
}
