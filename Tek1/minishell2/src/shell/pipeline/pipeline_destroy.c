/*
** EPITECH PROJECT, 2023
** pipeline_destroy.c
** File description:
** pipeline_destroy.c
*/

#include "shell/pipeline.h"

#include <stdlib.h>

void pipeline_destroy(pipeline_t *pipeline)
{
    if (pipeline == NULL)
        return;
    for (size_t i = 0; i < pipeline->length; i++)
        instruction_destroy(pipeline->instructions[i]);
    free(pipeline->instructions);
    free(pipeline);
}
