/*
** EPITECH PROJECT, 2024
** sv_disconnection_success.c
** File description:
** sv_disconnection_success.c
*/

#include "protocol/packet/disconnection_success.h"
#include "my/memory/allocation.h"

void sv_disconnection_success_packet_encode(
    sv_disconnection_success_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
}

bool sv_disconnection_success_packet_decode(
    sv_disconnection_success_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_u8(packet, &self->type);
}

void sv_disconnection_success_packet_destroy(
    sv_disconnection_success_packet_t *self
)
{
    deallocate(self);
}
