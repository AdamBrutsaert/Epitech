/*
** EPITECH PROJECT, 2023
** pipeline_print.c
** File description:
** pipeline_print.c
*/

#include "shell/pipeline_impl.h"

#include <stdio.h>

void pipeline_print(pipeline_t *pipeline)
{
    printf("\tPipeline:\n");
    printf("\t\tSeparator: ");
    if (pipeline->separator == SEPARATOR_SEMICOLON)
        printf(";\n");
    if (pipeline->separator == SEPARATOR_AND)
        printf("&&\n");
    if (pipeline->separator == SEPARATOR_OR)
        printf("||\n");
    if (pipeline->separator == SEPARATOR_NONE)
        printf("\n");
    for (size_t i = 0; i < VEC_LEN(pipeline->instructions); i++)
        instruction_print(VEC_GET(pipeline->instructions, i, instruction_t *));
}
