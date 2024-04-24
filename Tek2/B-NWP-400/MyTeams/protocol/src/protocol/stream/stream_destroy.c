/*
** EPITECH PROJECT, 2024
** stream_destroy.c
** File description:
** stream_destroy.c
*/

#include "protocol/stream.h"
#include "my/memory/allocation.h"

void stream_destroy(stream_t *self)
{
    socket_destroy(self->socket);
    vec_destroy(self->read_buffer);
    vec_destroy(self->write_buffer);
    for (size_t i = 0; i < VEC_LEN(self->packets); i++)
        packet_destroy(*(packet_t **)VEC_AT(self->packets, i));
    vec_destroy(self->packets);
    deallocate(self);
}
