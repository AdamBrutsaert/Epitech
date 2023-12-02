/*
** EPITECH PROJECT, 2022
** specification.c
** File description:
** Implementation of specification
*/

#include <stdlib.h>

#include "my.h"
#include "parsing/format.h"

format_resolution_array_t *format_resolution_array_create(void)
{
    format_resolution_array_t *array =
        malloc(sizeof(format_resolution_array_t));

    array->formats = NULL;
    array->length = 0;
    array->capacity = 0;
    return array;
}

void format_resolution_array_destroy(format_resolution_array_t *array)
{
    free(array->formats);
    free(array);
}

void format_resolution_array_push(
    format_resolution_array_t *array, format_resolution_t *spec)
{
    if (array->length == array->capacity) {
        array->capacity = array->capacity * 2 + !array->capacity;
        array->formats = my_realloc(array->formats,
            sizeof(format_resolution_t) * array->capacity,
            sizeof(format_resolution_t) * array->length);
    }
    array->formats[array->length++] = *spec;
}
