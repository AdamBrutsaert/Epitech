/*
** EPITECH PROJECT, 2024
** stream_pop_command.c
** File description:
** stream_pop_command.c
*/

#include "protocol/stream.h"

bool stream_pop_packet(stream_t *self, cl_sv_packet_t **packet)
{
    packet_t *raw;
    bool result;

    if (VEC_LEN(self->packets) == 0)
        return false;
    raw = *(packet_t **)VEC_AT(self->packets, 0);
    result = packet_pop_cl_sv_packet(raw, packet);
    packet_destroy(raw);
    vec_pop_front(self->packets);
    return result;
}
