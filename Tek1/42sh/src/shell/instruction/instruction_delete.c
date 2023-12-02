/*
** EPITECH PROJECT, 2023
** instruction_delete.c
** File description:
** instruction_delete.c
*/

#include "shell/instruction_impl.h"

#include <stdlib.h>

void instruction_delete(instruction_t *instruction)
{
    if (instruction == NULL)
        return;
    vec_clear_and_delete(instruction->arguments, free);
    vec_clear_and_delete(
        instruction->redirections,
        (deleter_t)redirection_delete
    );
    vec_delete(instruction->arguments);
    vec_delete(instruction->redirections);
    free(instruction);
}
