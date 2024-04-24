/*
** EPITECH PROJECT, 2024
** channel_load.c
** File description:
** channel_load.c
*/

#include "protocol/entities/channel.h"
#include "protocol/packet/type.h"

#include "my/memory/allocation.h"

channel_t *channel_load(
    const string_t *uuid,
    const string_t *team_uuid,
    const string_t *name,
    const string_t *description
)
{
    channel_t *self = allocate(sizeof(channel_t));

    self->uuid = string_clone(uuid);
    self->team_uuid = string_clone(team_uuid);
    self->name = string_clone_n(name, MAX_NAME_LENGTH);
    self->description = string_clone_n(description, MAX_DESCRIPTION_LENGTH);
    return self;
}
