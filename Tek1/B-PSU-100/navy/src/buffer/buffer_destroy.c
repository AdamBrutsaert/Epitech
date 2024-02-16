/*
** EPITECH PROJECT, 2023
** buffer_destroy.c
** File description:
** v
*/

#include "buffer.h"

#include <stdlib.h>

void buffer_destroy(buffer_t *buffer)
{
    free(buffer->bits);
    free(buffer);
}
