/*
** EPITECH PROJECT, 2024
** sv_create_channel.c
** File description:
** sv_create_channel.c
*/

#include "protocol/packet/create_channel.h"
#include "my/memory/allocation.h"

void sv_create_channel_packet_encode(
    sv_create_channel_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_channel(packet, self->channel);
}

bool sv_create_channel_packet_decode(
    sv_create_channel_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_channel(packet, &self->channel)
        && packet_pop_u8(packet, &self->type);
}

void sv_create_channel_packet_destroy(sv_create_channel_packet_t *self)
{
    channel_destroy(self->channel);
    deallocate(self);
}
