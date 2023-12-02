/*
** EPITECH PROJECT, 2023
** instruction_destroy.c
** File description:
** instruction_destroy.c
*/

#include "shell/instruction.h"

#include <stdlib.h>

void instruction_destroy(instruction_t *instruction)
{
    if (instruction == NULL)
        return;
    free(instruction->arguments);
    free(instruction->redirects);
    free(instruction);
}
