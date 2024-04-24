/*
** EPITECH PROJECT, 2024
** packet_push_thread.c
** File description:
** packet_push_thread.c
*/

#include "protocol/entities/thread.h"

void packet_push_thread(packet_t *self, const thread_t *thread)
{
    packet_push_string(self, thread->uuid);
    packet_push_string(self, thread->channel_uuid);
    packet_push_string(self, thread->user_uuid);
    packet_push_u64(self, thread->timestamp);
    packet_push_string(self, thread->title);
    packet_push_string(self, thread->body);
}
