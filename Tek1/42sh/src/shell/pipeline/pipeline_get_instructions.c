/*
** EPITECH PROJECT, 2023
** pipeline_get_instructions.c
** File description:
** pipeline_get_instructions.c
*/

#include "shell/pipeline_impl.h"

vec_t *pipeline_get_instructions(pipeline_t *pipeline)
{
    return pipeline->instructions;
}
