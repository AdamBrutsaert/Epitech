/*
** EPITECH PROJECT, 2023
** buffer_push.c
** File description:
** buffer_push.c
*/

#include "buffer.h"
#include "my.h"

#include <stdlib.h>

static int8_t buffer_grow(buffer_t *buffer, uint64_t capacity)
{
    bit_t *bits = malloc(sizeof(bit_t) * capacity);

    if (bits == NULL)
        return 84;
    my_memmove(bits, buffer->bits, sizeof(bit_t) * buffer->length);
    free(buffer->bits);
    buffer->bits = bits;
    buffer->capacity = capacity;
    return 0;
}

int8_t buffer_push(buffer_t *buffer, bit_t bit)
{
    if (buffer->length == buffer->capacity)
        if (buffer_grow(buffer, buffer->capacity * 2 + !buffer->capacity) == 84)
            return 84;
    buffer->bits[buffer->length] = bit;
    buffer->length++;
    return 0;
}
