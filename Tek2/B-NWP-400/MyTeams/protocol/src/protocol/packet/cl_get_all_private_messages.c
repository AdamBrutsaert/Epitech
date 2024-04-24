/*
** EPITECH PROJECT, 2024
** cl_get_all_private_messages.h
** File description:
** cl_get_all_private_messages.h
*/

#include "protocol/packet/get_all_private_messages.h"
#include "my/memory/allocation.h"

void cl_get_all_private_messages_packet_encode(
    cl_get_all_private_messages_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->uuid);
}

bool cl_get_all_private_messages_packet_decode(
    cl_get_all_private_messages_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->uuid)
        && packet_pop_u8(packet, &self->type);
}

void cl_get_all_private_messages_packet_destroy(
    cl_get_all_private_messages_packet_t *self
)
{
    string_destroy(self->uuid);
    deallocate(self);
}
