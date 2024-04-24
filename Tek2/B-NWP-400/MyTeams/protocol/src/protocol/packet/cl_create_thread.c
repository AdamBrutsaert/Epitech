/*
** EPITECH PROJECT, 2024
** cl_create_thread.c
** File description:
** cl_create_thread.c
*/

#include "protocol/packet/create_thread.h"
#include "my/memory/allocation.h"

void cl_create_thread_packet_encode(
    cl_create_thread_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->team_uuid);
    packet_push_string(packet, self->channel_uuid);
    packet_push_string(packet, self->title);
    packet_push_string(packet, self->body);
}

bool cl_create_thread_packet_decode(
    cl_create_thread_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->body)
        && packet_pop_string(packet, &self->title)
        && packet_pop_string(packet, &self->channel_uuid)
        && packet_pop_string(packet, &self->team_uuid)
        && packet_pop_u8(packet, &self->type);
}

void cl_create_thread_packet_destroy(cl_create_thread_packet_t *self)
{
    string_destroy(self->body);
    string_destroy(self->title);
    string_destroy(self->channel_uuid);
    string_destroy(self->team_uuid);
    deallocate(self);
}
