/*
** EPITECH PROJECT, 2024
** sv_created_reply_succesfully.c
** File description:
** sv_created_reply_succesfully.c
*/

#include "protocol/packet/create_reply.h"

#include "my/memory/allocation.h"

void sv_created_reply_successfully_packet_encode(
    sv_created_reply_successfully_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_reply(packet, self->reply);
}

bool sv_created_reply_successfully_packet_decode(
    sv_created_reply_successfully_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_reply(packet, &self->reply)
        && packet_pop_u8(packet, &self->type);
}

void sv_created_reply_successfully_packet_destroy(
    sv_created_reply_successfully_packet_t *self
)
{
    reply_destroy(self->reply);
    deallocate(self);
}
