/*
** EPITECH PROJECT, 2023
** pipeline_set_separator.c
** File description:
** pipeline_set_separator.c
*/

#include "shell/pipeline_impl.h"

void pipeline_set_separator(pipeline_t *pipeline, separator_t separator)
{
    pipeline->separator = separator;
}
