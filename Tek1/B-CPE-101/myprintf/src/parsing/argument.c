/*
** EPITECH PROJECT, 2022
** argument.c
** File description:
** Implementation of argument
*/

#include <stdlib.h>

#include "parsing/argument.h"
#include "my.h"

argument_array_t *argument_array_create(void)
{
    argument_array_t *array = malloc(sizeof(argument_array_t));

    array->args = NULL;
    array->length = 0;
    array->capacity = 0;
    return array;
}

void argument_array_destroy(argument_array_t *array)
{
    free(array->args);
    free(array);
}

static void argument_array_push(argument_array_t *array, argument_t *argument)
{
    if (array->length == array->capacity) {
        array->capacity = array->capacity * 2 + !array->capacity;
        array->args = my_realloc(array->args,
            sizeof(argument_t) * array->capacity,
            sizeof(argument_t) * array->length);
    }
    array->args[array->length++] = *argument;
}

void argument_array_set(argument_array_t *array, uint32_t index, type_t type)
{
    argument_t empty = { TYPE_UNDEFINED, -1 };

    while (array->length <= index)
        argument_array_push(array, &empty);
    array->args[index].type = type;
}
