/*
** EPITECH PROJECT, 2024
** packet_pop_reply.c
** File description:
** packet_pop_reply.c
*/

#include "protocol/entities/reply.h"

#include "my/memory/allocation.h"

#include <string.h>

static void destroy_reply(reply_t *reply)
{
    if (reply->thread_uuid)
        string_destroy(reply->thread_uuid);
    if (reply->user_uuid)
        string_destroy(reply->user_uuid);
    if (reply->body)
        string_destroy(reply->body);
    deallocate(reply);
}

bool packet_pop_reply(packet_t *self, reply_t **reply)
{
    uint64_t ts;

    *reply = allocate(sizeof(reply_t));
    memset(*reply, 0, sizeof(reply_t));
    if (!packet_pop_string(self, &(*reply)->body)
        || !packet_pop_u64(self, &ts)
        || !packet_pop_string(self, &(*reply)->user_uuid)
        || !packet_pop_string(self, &(*reply)->thread_uuid)) {
        destroy_reply(*reply);
        return false;
    }
    (*reply)->timestamp = ts;
    return true;
}
