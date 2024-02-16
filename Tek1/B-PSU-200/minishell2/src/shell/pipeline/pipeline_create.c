/*
** EPITECH PROJECT, 2023
** pipeline_create.c
** File description:
** pipeline_create.c
*/

#include "shell/pipeline.h"
#include "my/memory.h"

#include <stdlib.h>

pipeline_t *pipeline_create(void)
{
    pipeline_t *pipeline = malloc(sizeof(pipeline_t));

    if (pipeline == NULL)
        return NULL;
    my_memset(pipeline, 0, sizeof(pipeline_t));
    return pipeline;
}
