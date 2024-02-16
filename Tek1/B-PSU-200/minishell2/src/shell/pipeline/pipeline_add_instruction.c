/*
** EPITECH PROJECT, 2023
** pipeline_add_instruction.c
** File description:
** pipeline_add_instruction.c
*/

#include "shell/pipeline.h"
#include "my/memory.h"

#include <stdlib.h>

static bool grow(pipeline_t *pipeline)
{
    size_t capacity = pipeline->capacity * 2 + !pipeline->capacity;
    instruction_t **instructions = malloc(sizeof(instruction_t *) * capacity);

    if (instructions == NULL)
        return false;
    my_memmove(
        instructions,
        pipeline->instructions,
        sizeof(instruction_t *) * pipeline->length
    );
    free(pipeline->instructions);
    pipeline->instructions = instructions;
    pipeline->capacity = capacity;
    return true;
}

bool pipeline_add_instruction(pipeline_t *pipeline, instruction_t *instruction)
{
    if (pipeline->length == pipeline->capacity && !grow(pipeline))
        return false;
    pipeline->instructions[pipeline->length] = instruction;
    pipeline->length++;
    return true;
}
