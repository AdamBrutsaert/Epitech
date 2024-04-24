/*
** EPITECH PROJECT, 2024
** team_create.c
** File description:
** team_create.c
*/

#include "protocol/entities/team.h"
#include "protocol/packet/type.h"

#include "my/memory/allocation.h"

team_t *team_create(const string_t *name, const string_t *description)
{
    team_t *self = allocate(sizeof(team_t));

    self->uuid = string_create_random_uuid();
    self->name = string_clone_n(name, MAX_NAME_LENGTH);
    self->description = string_clone_n(description, MAX_DESCRIPTION_LENGTH);
    return self;
}
