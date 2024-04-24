/*
** EPITECH PROJECT, 2024
** cl_get_channel_info.c
** File description:
** cl_get_channel_info.c
*/

#include "protocol/packet/get_channel_info.h"
#include "my/memory/allocation.h"

void cl_get_channel_info_packet_encode(
    cl_get_channel_info_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->team_uuid);
    packet_push_string(packet, self->channel_uuid);
}

bool cl_get_channel_info_packet_decode(
    cl_get_channel_info_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->channel_uuid)
        && packet_pop_string(packet, &self->team_uuid)
        && packet_pop_u8(packet, &self->type);
}

void cl_get_channel_info_packet_destroy(
    cl_get_channel_info_packet_t *self
)
{
    string_destroy(self->team_uuid);
    string_destroy(self->channel_uuid);
    deallocate(self);
}
