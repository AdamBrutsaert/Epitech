/*
** EPITECH PROJECT, 2024
** packet_push_channel.c
** File description:
** packet_push_channel.c
*/

#include "protocol/entities/channel.h"

void packet_push_channel(packet_t *self, const channel_t *channel)
{
    packet_push_string(self, channel->uuid);
    packet_push_string(self, channel->team_uuid);
    packet_push_string(self, channel->name);
    packet_push_string(self, channel->description);
}
