/*
** EPITECH PROJECT, 2024
** packet_push_reply_vec.c
** File description:
** packet_push_reply_vec.c
*/

#include "protocol/entities/reply.h"

void packet_push_reply_vec(packet_t *self, const vec_t *replys)
{
    for (size_t i = 0; i < VEC_LEN(replys); i++)
        packet_push_reply(self, *(reply_t **)VEC_AT(replys, i));
    packet_push_u64(self, VEC_LEN(replys));
}
