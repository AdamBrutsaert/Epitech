/*
** EPITECH PROJECT, 2024
** cl_send_private_message.c
** File description:
** cl_send_private_message.c
*/

#include "protocol/packet/send_private_message.h"
#include "my/memory/allocation.h"

void cl_send_private_message_packet_encode(
    cl_send_private_message_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->message);
    packet_push_string(packet, self->to_uuid);
}

bool cl_send_private_message_packet_decode(
    cl_send_private_message_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->to_uuid)
        && packet_pop_string(packet, &self->message)
        && packet_pop_u8(packet, &self->type);
}

void cl_send_private_message_packet_destroy(
    cl_send_private_message_packet_t *self
)
{
    string_destroy(self->message);
    string_destroy(self->to_uuid);
    deallocate(self);
}
