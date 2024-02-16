/*
** EPITECH PROJECT, 2023
** instruction_add_argument.c
** File description:
** instruction_add_argument.c
*/

#include "shell/instruction.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(instruction_t *instruction)
{
    size_t capacity = instruction->arguments_capacity * 2
        + !instruction->arguments_capacity;
    char **arguments = malloc(sizeof(char *) * (capacity + 1));

    if (arguments == NULL)
        return false;
    my_memmove(
        arguments,
        instruction->arguments,
        sizeof(char *) * instruction->arguments_length
    );
    my_memset(
        arguments + instruction->arguments_length,
        0,
        sizeof(char *) * (capacity - instruction->arguments_length + 1)
    );
    free(instruction->arguments);
    instruction->arguments = arguments;
    instruction->arguments_capacity = capacity;
    return true;
}

bool instruction_add_argument(instruction_t *instruction, char *argument)
{
    if (instruction->arguments_length == instruction->arguments_capacity
        && !grow(instruction))
        return false;
    instruction->arguments[instruction->arguments_length] = argument;
    instruction->arguments_length++;
    return true;
}
