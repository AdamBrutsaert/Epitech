/*
** EPITECH PROJECT, 2024
** stream_discard_packet.c
** File description:
** stream_discard_packet.c
*/

#include "protocol/stream.h"

void stream_discard_packet(stream_t *self)
{
    if (VEC_LEN(self->packets) == 0)
        return;
    packet_destroy(*(packet_t **)VEC_AT(self->packets, 0));
    vec_pop_front(self->packets);
}
