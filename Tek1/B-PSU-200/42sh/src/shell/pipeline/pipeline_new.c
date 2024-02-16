/*
** EPITECH PROJECT, 2023
** pipeline_new.c
** File description:
** pipeline_new.c
*/

#include "shell/pipeline_impl.h"

#include <stdlib.h>

pipeline_t *pipeline_new(void)
{
    pipeline_t *pipeline = calloc(1, sizeof(pipeline_t));

    if (pipeline == NULL)
        return NULL;
    pipeline->instructions = vec_new(sizeof(instruction_t *));
    if (pipeline->instructions == NULL) {
        pipeline_delete(pipeline);
        return NULL;
    }
    return pipeline;
}
