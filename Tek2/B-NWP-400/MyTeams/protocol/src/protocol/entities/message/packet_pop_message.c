/*
** EPITECH PROJECT, 2024
** packet_pop_message.c
** File description:
** packet_pop_message.c
*/

#include "protocol/entities/message.h"

#include "my/memory/allocation.h"

bool packet_pop_message(packet_t *self, struct message **message)
{
    string_t *from_uuid;
    string_t *to_uuid;
    string_t *message_str;
    uint64_t timestamp;

    if (!packet_pop_u64(self, &timestamp)
        || !packet_pop_string(self, &message_str))
        return false;
    if (!packet_pop_string(self, &to_uuid)) {
        string_destroy(message_str);
        return false;
    }
    if (!packet_pop_string(self, &from_uuid)) {
        string_destroy(to_uuid);
        string_destroy(message_str);
        return false;
    }
    *message = allocate(sizeof(message_t));
    **message = (message_t){from_uuid, to_uuid, message_str, timestamp};
    return true;
}
