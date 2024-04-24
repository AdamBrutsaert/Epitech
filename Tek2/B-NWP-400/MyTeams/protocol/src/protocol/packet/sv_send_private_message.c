/*
** EPITECH PROJECT, 2024
** sv_send_private_message.c
** File description:
** sv_send_private_message.c
*/

#include "protocol/packet/send_private_message.h"
#include "my/memory/allocation.h"

void sv_send_private_message_packet_encode(
    sv_send_private_message_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->message);
    packet_push_string(packet, self->from_uuid);
}

bool sv_send_private_message_packet_decode(
    sv_send_private_message_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->from_uuid)
        && packet_pop_string(packet, &self->message)
        && packet_pop_u8(packet, &self->type);
}

void sv_send_private_message_packet_destroy(
    sv_send_private_message_packet_t *self
)
{
    string_destroy(self->message);
    string_destroy(self->from_uuid);
    deallocate(self);
}
