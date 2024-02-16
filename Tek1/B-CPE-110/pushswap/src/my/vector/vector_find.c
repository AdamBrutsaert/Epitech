/*
** EPITECH PROJECT, 2022
** vector_find.c
** File description:
** vector_find.c
*/

#include "my/vector.h"
#include "my/memory.h"

u64_t vector_find(vector_t *vector, void *value)
{
    u64_t index = 0;

    for (; index < vector->length; index++) {
        if (!my_memcmp((i8_t *)vector->values + index * vector->stride, value,
            vector->stride))
            break;
    }
    return index;
}
