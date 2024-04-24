/*
** EPITECH PROJECT, 2024
** team_load.c
** File description:
** team_load.c
*/

#include "protocol/entities/team.h"
#include "protocol/packet/type.h"

#include "my/memory/allocation.h"

team_t *team_load(
    const string_t *uuid,
    const string_t *name,
    const string_t *description
)
{
    team_t *self = allocate(sizeof(team_t));

    self->uuid = string_clone(uuid);
    self->name = string_clone_n(name, MAX_NAME_LENGTH);
    self->description = string_clone_n(description, MAX_DESCRIPTION_LENGTH);
    return self;
}
