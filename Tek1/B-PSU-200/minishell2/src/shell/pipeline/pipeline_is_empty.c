/*
** EPITECH PROJECT, 2023
** pipeline_is_empty.c
** File description:
** pipeline_is_empty.c
*/

#include "shell/pipeline.h"

bool pipeline_is_empty(pipeline_t *pipeline)
{
    for (size_t i = 0; i < pipeline->length; i++) {
        if (!instruction_is_empty(pipeline->instructions[i]))
            return false;
    }
    return true;
}
