/*
** EPITECH PROJECT, 2024
** state_is_user_subscribed.c
** File description:
** state_is_user_subscribed.c
*/

#include "state.h"

bool state_is_user_subscribed(state_t *self, user_t *user, team_t *team)
{
    team_subscription_t *sub;

    for (size_t i = 0; i < VEC_LEN(self->team_subscriptions); i++) {
        sub = *(team_subscription_t **)VEC_AT(self->team_subscriptions, i);
        if (!string_compare(sub->team_uuid, team->uuid)
            && !string_compare(sub->user_uuid, user->uuid))
            return true;
    }
    return false;
}
