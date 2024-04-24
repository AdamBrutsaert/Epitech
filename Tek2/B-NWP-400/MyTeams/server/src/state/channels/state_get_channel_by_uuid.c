/*
** EPITECH PROJECT, 2024
** state_get_channel_by_uuid.c
** File description:
** state_get_channel_by_uuid.c
*/

#include "state.h"

channel_t *state_get_channel_by_uuid(state_t *self, const string_t *uuid)
{
    channel_t *channel;

    for (size_t i = 0; i < VEC_LEN(self->channels); i++) {
        channel = *(channel_t **)VEC_AT(self->channels, i);
        if (!string_compare(channel->uuid, uuid))
            return channel;
    }
    return nullptr;
}
