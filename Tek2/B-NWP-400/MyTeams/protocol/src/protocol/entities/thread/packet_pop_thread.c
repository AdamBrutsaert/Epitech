/*
** EPITECH PROJECT, 2024
** packet_pop_thread.c
** File description:
** packet_pop_thread.c
*/

#include "protocol/entities/thread.h"

#include "my/memory/allocation.h"

#include <string.h>

static void destroy_thread(thread_t *thread)
{
    if (thread->uuid)
        string_destroy(thread->uuid);
    if (thread->channel_uuid)
        string_destroy(thread->channel_uuid);
    if (thread->user_uuid)
        string_destroy(thread->user_uuid);
    if (thread->title)
        string_destroy(thread->title);
    if (thread->body)
        string_destroy(thread->body);
    deallocate(thread);
}

bool packet_pop_thread(packet_t *self, thread_t **thread)
{
    uint64_t ts;

    *thread = allocate(sizeof(thread_t));
    memset(*thread, 0, sizeof(thread_t));
    if (!packet_pop_string(self, &(*thread)->body)
        || !packet_pop_string(self, &(*thread)->title)
        || !packet_pop_u64(self, &ts)
        || !packet_pop_string(self, &(*thread)->user_uuid)
        || !packet_pop_string(self, &(*thread)->channel_uuid)
        || !packet_pop_string(self, &(*thread)->uuid)) {
        destroy_thread(*thread);
        return false;
    }
    (*thread)->timestamp = ts;
    return true;
}
