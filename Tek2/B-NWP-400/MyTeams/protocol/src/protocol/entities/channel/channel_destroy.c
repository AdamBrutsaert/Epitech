/*
** EPITECH PROJECT, 2024
** channel_destroy.c
** File description:
** channel_destroy.c
*/

#include "protocol/entities/channel.h"

#include "my/memory/allocation.h"

void channel_destroy(channel_t *channel)
{
    string_destroy(channel->uuid);
    string_destroy(channel->team_uuid);
    string_destroy(channel->name);
    string_destroy(channel->description);
    deallocate(channel);
}
