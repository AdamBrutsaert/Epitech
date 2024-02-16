/*
** EPITECH PROJECT, 2023
** buffer_pop.c
** File description:
** buffer_pop.c
*/

#include "buffer.h"

bit_t buffer_pop(buffer_t *buffer)
{
    if (buffer->length == 0)
        return BIT_NONE;
    buffer->length--;
    return buffer->bits[buffer->length];
}
