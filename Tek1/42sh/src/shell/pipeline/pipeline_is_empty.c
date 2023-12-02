/*
** EPITECH PROJECT, 2023
** pipeline_is_empty.c
** File description:
** pipeline_is_empty.c
*/

#include "shell/pipeline_impl.h"

bool pipeline_is_empty(pipeline_t *pipeline)
{
    instruction_t *instruction;

    for (size_t i = 0; i < VEC_LEN(pipeline->instructions); i++) {
        instruction = VEC_GET(pipeline->instructions, i, instruction_t *);
        if (!instruction_is_empty(instruction))
            return false;
    }
    return true;
}
