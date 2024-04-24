/*
** EPITECH PROJECT, 2024
** sv_created_channel_succesfully.c
** File description:
** sv_created_channel_succesfully.c
*/

#include "protocol/packet/create_channel.h"

#include "my/memory/allocation.h"

void sv_created_channel_successfully_packet_encode(
    sv_created_channel_successfully_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_channel(packet, self->channel);
}

bool sv_created_channel_successfully_packet_decode(
    sv_created_channel_successfully_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_channel(packet, &self->channel)
        && packet_pop_u8(packet, &self->type);
}

void sv_created_channel_successfully_packet_destroy(
    sv_created_channel_successfully_packet_t *self
)
{
    channel_destroy(self->channel);
    deallocate(self);
}
