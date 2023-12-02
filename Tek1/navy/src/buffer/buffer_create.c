/*
** EPITECH PROJECT, 2023
** buffer_create.c
** File description:
** buffer_create.c
*/

#include "buffer.h"

#include <stdlib.h>

buffer_t *buffer_create(void)
{
    buffer_t *buffer = malloc(sizeof(buffer_t));

    buffer->length = 0;
    buffer->capacity = 0;
    buffer->bits = NULL;
    return buffer;
}
