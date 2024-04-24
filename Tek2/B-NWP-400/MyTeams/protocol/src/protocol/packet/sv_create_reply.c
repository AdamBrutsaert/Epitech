/*
** EPITECH PROJECT, 2024
** sv_create_reply.c
** File description:
** sv_create_reply.c
*/

#include "protocol/packet/create_reply.h"
#include "my/memory/allocation.h"

void sv_create_reply_packet_encode(
    sv_create_reply_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_reply(packet, self->reply);
    packet_push_team(packet, self->team);
}

bool sv_create_reply_packet_decode(
    sv_create_reply_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_team(packet, &self->team)
        && packet_pop_reply(packet, &self->reply)
        && packet_pop_u8(packet, &self->type);
}

void sv_create_reply_packet_destroy(sv_create_reply_packet_t *self)
{
    team_destroy(self->team);
    reply_destroy(self->reply);
    deallocate(self);
}
