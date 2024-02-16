/*
** EPITECH PROJECT, 2023
** network_buffer.c
** File description:
** network_buffer.c
*/

#include "network.h"

#include <stddef.h>

void network_buffer(network_operation_t operation, void *data)
{
    static buffer_t *buffer = NULL;

    if (operation == CREATE)
        buffer = buffer_create();
    if (operation == DESTROY)
        buffer_destroy(buffer);
    if (operation == LENGTH)
        *(uint64_t *)data = buffer_get_length(buffer);
    if (operation == PUSH)
        buffer_push(buffer, *(bit_t *)data);
    if (operation == POP)
        *(bit_t *)data = buffer_pop(buffer);
}
