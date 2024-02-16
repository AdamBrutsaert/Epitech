/*
** EPITECH PROJECT, 2023
** pipeline_delete.c
** File description:
** pipeline_delete.c
*/

#include "shell/pipeline_impl.h"

#include <stdlib.h>

void pipeline_delete(pipeline_t *pipeline)
{
    if (pipeline == NULL)
        return;
    vec_clear_and_delete(pipeline->instructions, (deleter_t)instruction_delete);
    vec_delete(pipeline->instructions);
    free(pipeline);
}
