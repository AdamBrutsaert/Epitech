/*
** EPITECH PROJECT, 2024
** cl_list_threads.c
** File description:
** cl_list_threads.c
*/

#include "protocol/packet/list_threads.h"
#include "my/memory/allocation.h"

void cl_list_threads_packet_encode(
    cl_list_threads_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->team_uuid);
    packet_push_string(packet, self->channel_uuid);
}

bool cl_list_threads_packet_decode(
    cl_list_threads_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->channel_uuid)
        && packet_pop_string(packet, &self->team_uuid)
        && packet_pop_u8(packet, &self->type);
}

void cl_list_threads_packet_destroy(cl_list_threads_packet_t *self)
{
    string_destroy(self->team_uuid);
    string_destroy(self->channel_uuid);
    deallocate(self);
}
