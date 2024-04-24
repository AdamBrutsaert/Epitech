/*
** EPITECH PROJECT, 2024
** stream_peek_packet_type.c
** File description:
** stream_peek_packet_type.c
*/

#include "protocol/stream.h"

packet_type_t stream_peek_packet_type(stream_t *self)
{
    packet_t *packet;
    packet_type_t type;

    if (VEC_LEN(self->packets) == 0)
        return PACKET_TYPE_INVALID;
    packet = *(packet_t **)VEC_AT(self->packets, 0);
    if (PACKET_LEN(packet) < sizeof(packet_type_t))
        return PACKET_TYPE_INVALID;
    type = *(packet_type_t *)PACKET_DATA(packet);
    return type >= PACKET_TYPE_COUNT ? PACKET_TYPE_INVALID : type;
}
