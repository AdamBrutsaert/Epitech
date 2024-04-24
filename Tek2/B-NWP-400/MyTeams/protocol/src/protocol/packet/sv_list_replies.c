/*
** EPITECH PROJECT, 2024
** sv_list_replies.c
** File description:
** sv_list_replies.c
*/

#include "protocol/packet/list_replies.h"

#include "protocol/entities/reply.h"
#include "my/memory/allocation.h"

void sv_list_replies_packet_encode(
    sv_list_replies_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_reply_vec(packet, self->replies);
}

bool sv_list_replies_packet_decode(
    sv_list_replies_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_reply_vec(packet, &self->replies)
        && packet_pop_u8(packet, &self->type);
}

void sv_list_replies_packet_destroy(sv_list_replies_packet_t *self)
{
    for (size_t i = 0; i < VEC_LEN(self->replies); i++)
        reply_destroy(*(reply_t **)VEC_AT(self->replies, i));
    vec_destroy(self->replies);
    deallocate(self);
}
