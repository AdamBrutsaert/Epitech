/*
** EPITECH PROJECT, 2024
** team_subscription_create.c
** File description:
** team_subscription_create.c
*/

#include "protocol/entities/team_subscription.h"

#include "my/memory/allocation.h"

team_subscription_t *team_subscription_create(
    const string_t *team_uuid,
    const string_t *user_uuid
)
{
    team_subscription_t *self = allocate(sizeof(team_subscription_t));

    self->team_uuid = string_clone(team_uuid);
    self->user_uuid = string_clone(user_uuid);
    return self;
}
