/*
** EPITECH PROJECT, 2023
** instruction_create.c
** File description:
** instruction_create.c
*/

#include "shell/instruction.h"
#include "my/memory.h"

#include <stdlib.h>

instruction_t *instruction_create(void)
{
    instruction_t *instruction = malloc(sizeof(instruction_t));

    if (instruction == NULL)
        return NULL;
    my_memset(instruction, 0, sizeof(instruction_t));
    instruction->arguments = malloc(sizeof(char *));
    if (instruction->arguments == NULL) {
        instruction_destroy(instruction);
        return NULL;
    }
    instruction->arguments[0] = NULL;
    instruction->pipefd[0] = -1;
    instruction->pipefd[1] = -1;
    instruction->pid = -1;
    instruction->stdin_copy = -1;
    instruction->stdout_copy = -1;
    return instruction;
}
