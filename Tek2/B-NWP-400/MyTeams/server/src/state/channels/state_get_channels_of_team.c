/*
** EPITECH PROJECT, 2024
** state_get_channels_of_team.c
** File description:
** state_get_channels_of_team.c
*/

#include "state.h"

vec_t *state_get_channels_of_team(state_t *self, team_t *team)
{
    vec_t *channels = vec_create(sizeof(channel_t *));
    channel_t *channel;

    for (size_t i = 0; i < VEC_LEN(self->channels); i++) {
        channel = *(channel_t **)VEC_AT(self->channels, i);
        if (!string_compare(channel->team_uuid, team->uuid))
            vec_push_back(channels, &channel);
    }
    return channels;
}
