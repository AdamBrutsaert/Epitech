/*
** EPITECH PROJECT, 2022
** vector_pop.c
** File description:
** vector_pop.c
*/

#include "my/vector.h"

void vector_pop(vector_t *vector)
{
    vector->length -= !!vector->length;
}
