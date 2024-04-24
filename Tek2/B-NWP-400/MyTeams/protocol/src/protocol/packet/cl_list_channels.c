/*
** EPITECH PROJECT, 2024
** cl_list_channels.c
** File description:
** cl_list_channels.c
*/

#include "protocol/packet/list_channels.h"
#include "my/memory/allocation.h"

void cl_list_channels_packet_encode(
    cl_list_channels_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->team_uuid);
}

bool cl_list_channels_packet_decode(
    cl_list_channels_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->team_uuid)
        && packet_pop_u8(packet, &self->type);
}

void cl_list_channels_packet_destroy(cl_list_channels_packet_t *self)
{
    string_destroy(self->team_uuid);
    deallocate(self);
}
