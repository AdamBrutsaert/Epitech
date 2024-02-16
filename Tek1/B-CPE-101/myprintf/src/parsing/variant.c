/*
** EPITECH PROJECT, 2022
** variant.c
** File description:
** Implementation of variant
*/

#include <stdlib.h>

#include "parsing/variant.h"
#include "my.h"

variant_array_t *variant_array_create(void)
{
    variant_array_t *array = malloc(sizeof(variant_array_t));

    array->vars = NULL;
    array->length = 0;
    array->capacity = 0;
    return array;
}

void variant_array_destroy(variant_array_t *array)
{
    free(array->vars);
    free(array);
}

int32_t variant_array_push(variant_array_t *array, variant_t *variant)
{
    if (array->length == array->capacity) {
        array->capacity = array->capacity * 2 + !array->capacity;
        array->vars = my_realloc(array->vars,
            sizeof(variant_t) * array->capacity,
            sizeof(variant_t) * array->length);
    }
    array->vars[array->length] = *variant;
    return array->length++;
}
