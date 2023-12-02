/*
** EPITECH PROJECT, 2023
** instruction_new.c
** File description:
** instruction_new.c
*/

#include "shell/instruction_impl.h"

#include <stdlib.h>

instruction_t *instruction_new(void)
{
    instruction_t *instruction = calloc(1, sizeof(instruction_t));
    void *dummy = NULL;

    if (instruction == NULL)
        return NULL;
    instruction->redirections = vec_new(sizeof(redirection_t *));
    instruction->arguments = vec_new(sizeof(char *));
    if (instruction->redirections == NULL || instruction->arguments == NULL) {
        instruction_delete(instruction);
        return NULL;
    }
    if (!VEC_PUSH(instruction->arguments, dummy)) {
        instruction_delete(instruction);
        return NULL;
    }
    return instruction;
}
