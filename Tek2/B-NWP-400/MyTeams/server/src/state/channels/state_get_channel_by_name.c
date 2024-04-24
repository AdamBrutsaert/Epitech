/*
** EPITECH PROJECT, 2024
** state_get_channel_by_name.c
** File description:
** state_get_channel_by_name.c
*/

#include "state.h"

channel_t *state_get_channel_by_name(
    state_t *self,
    team_t *team,
    const string_t *name
)
{
    channel_t *channel;

    for (size_t i = 0; i < VEC_LEN(self->channels); i++) {
        channel = *(channel_t **)VEC_AT(self->channels, i);
        if (!string_compare(channel->name, name)
            && !string_compare(channel->team_uuid, team->uuid))
            return channel;
    }
    return nullptr;
}
