/*
** EPITECH PROJECT, 2024
** packet_pop_channel.c
** File description:
** packet_pop_channel.c
*/

#include "protocol/entities/channel.h"

#include "my/memory/allocation.h"

#include <string.h>

static void destroy_channel(channel_t *channel)
{
    if (channel->uuid)
        string_destroy(channel->uuid);
    if (channel->team_uuid)
        string_destroy(channel->team_uuid);
    if (channel->name)
        string_destroy(channel->name);
    if (channel->description)
        string_destroy(channel->description);
    deallocate(channel);
}

bool packet_pop_channel(packet_t *self, channel_t **channel)
{
    *channel = allocate(sizeof(channel_t));
    memset(*channel, 0, sizeof(channel_t));
    if (!packet_pop_string(self, &(*channel)->description)
        || !packet_pop_string(self, &(*channel)->name)
        || !packet_pop_string(self, &(*channel)->team_uuid)
        || !packet_pop_string(self, &(*channel)->uuid)) {
        destroy_channel(*channel);
        return false;
    }
    return true;
}
