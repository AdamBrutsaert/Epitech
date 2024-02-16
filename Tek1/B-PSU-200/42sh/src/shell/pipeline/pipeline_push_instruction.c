/*
** EPITECH PROJECT, 2023
** pipeline_push_instruction.c
** File description:
** pipeline_push_instruction.c
*/

#include "shell/pipeline_impl.h"

bool pipeline_push_instruction(pipeline_t *pipeline, instruction_t *instruction)
{
    return VEC_PUSH(pipeline->instructions, instruction);
}
