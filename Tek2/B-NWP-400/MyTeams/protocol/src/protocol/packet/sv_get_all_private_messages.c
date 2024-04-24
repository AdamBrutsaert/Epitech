/*
** EPITECH PROJECT, 2024
** sv_get_all_private_messages.c
** File description:
** sv_get_all_private_messages.c
*/

#include "protocol/packet/get_all_private_messages.h"

#include "protocol/entities/message.h"
#include "my/memory/allocation.h"

void sv_get_all_private_messages_packet_encode(
    sv_get_all_private_messages_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_message_vec(packet, self->messages);
}

bool sv_get_all_private_messages_packet_decode(
    sv_get_all_private_messages_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_message_vec(packet, &self->messages)
        && packet_pop_u8(packet, &self->type);
}

void sv_get_all_private_messages_packet_destroy(
    sv_get_all_private_messages_packet_t *self
)
{
    for (size_t i = 0; i < VEC_LEN(self->messages); i++)
        message_destroy(*(message_t **)VEC_AT(self->messages, i));
    vec_destroy(self->messages);
    deallocate(self);
}
