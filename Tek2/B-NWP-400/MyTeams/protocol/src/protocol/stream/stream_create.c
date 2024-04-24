/*
** EPITECH PROJECT, 2024
** stream_create.c
** File description:
** stream_create.c
*/

#include "protocol/stream.h"
#include "my/memory/allocation.h"

stream_t *stream_create(socket_t *socket)
{
    stream_t *self = allocate(sizeof(stream_t));

    self->socket = socket;
    self->packets = vec_create(sizeof(packet_t *));
    self->read_buffer = vec_create(sizeof(uint8_t));
    self->write_buffer = vec_create(sizeof(uint8_t));
    return self;
}
