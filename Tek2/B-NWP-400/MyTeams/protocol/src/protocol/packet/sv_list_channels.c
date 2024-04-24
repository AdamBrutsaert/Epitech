/*
** EPITECH PROJECT, 2024
** sv_list_channels.c
** File description:
** sv_list_channels.c
*/

#include "protocol/packet/list_channels.h"

#include "protocol/entities/channel.h"
#include "my/memory/allocation.h"

void sv_list_channels_packet_encode(
    sv_list_channels_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_channel_vec(packet, self->channels);
}

bool sv_list_channels_packet_decode(
    sv_list_channels_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_channel_vec(packet, &self->channels)
        && packet_pop_u8(packet, &self->type);
}

void sv_list_channels_packet_destroy(sv_list_channels_packet_t *self)
{
    for (size_t i = 0; i < VEC_LEN(self->channels); i++)
        channel_destroy(*(channel_t **)VEC_AT(self->channels, i));
    vec_destroy(self->channels);
    deallocate(self);
}
