/*
** EPITECH PROJECT, 2024
** packet_push_message.c
** File description:
** packet_push_message.c
*/

#include "protocol/entities/message.h"

void packet_push_message(packet_t *self, const message_t *message)
{
    packet_push_string(self, message->from_uuid);
    packet_push_string(self, message->to_uuid);
    packet_push_string(self, message->message);
    packet_push_u64(self, message->timestamp);
}
