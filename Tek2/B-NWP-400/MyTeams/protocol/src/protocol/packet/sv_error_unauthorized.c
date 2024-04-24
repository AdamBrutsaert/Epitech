/*
** EPITECH PROJECT, 2024
** sv_error_unauthorized.c
** File description:
** sv_error_unauthorized.c
*/

#include "protocol/packet/error_unauthorized.h"
#include "my/memory/allocation.h"

void sv_error_unauthorized_packet_encode(
    sv_error_unauthorized_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
}

bool sv_error_unauthorized_packet_decode(
    sv_error_unauthorized_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_u8(packet, &self->type);
}

void sv_error_unauthorized_packet_destroy(
    sv_error_unauthorized_packet_t *self
)
{
    deallocate(self);
}
