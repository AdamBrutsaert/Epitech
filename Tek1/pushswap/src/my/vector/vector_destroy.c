/*
** EPITECH PROJECT, 2022
** vector_destroy.c
** File description:
** vector_destroy.c
*/

#include "my/vector.h"
#include "my/memory.h"

void vector_destroy(vector_t *vector)
{
    my_free(vector->values);
}
