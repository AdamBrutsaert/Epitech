/*
** EPITECH PROJECT, 2023
** pipeline_debug.c
** File description:
** pipeline_debug.c
*/

#include "shell/pipeline.h"
#include "my/stdio.h"

static void print_separator(pipeline_t *pipeline)
{
    my_puts("    Separator: ");
    if (pipeline->separator == SEPARATOR_NEWLINE)
        my_puts("\\n");
    if (pipeline->separator == SEPARATOR_SEMICOLON)
        my_putc(';');
    my_putc('\n');
}

void pipeline_debug(pipeline_t *pipeline)
{
    my_puts("  Pipeline:\n");
    print_separator(pipeline);
    for (size_t i = 0; i < pipeline->length; i++)
        instruction_debug(pipeline->instructions[i]);
}
