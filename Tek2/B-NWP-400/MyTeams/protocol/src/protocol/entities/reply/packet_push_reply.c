/*
** EPITECH PROJECT, 2024
** packet_push_reply.c
** File description:
** packet_push_reply.c
*/

#include "protocol/entities/reply.h"

void packet_push_reply(packet_t *self, const reply_t *reply)
{
    packet_push_string(self, reply->thread_uuid);
    packet_push_string(self, reply->user_uuid);
    packet_push_u64(self, reply->timestamp);
    packet_push_string(self, reply->body);
}
