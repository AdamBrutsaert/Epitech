/*
** EPITECH PROJECT, 2024
** state_get_subscription.c
** File description:
** state_get_subscription.c
*/

#include "state.h"

team_subscription_t *state_get_subscription(
    state_t *self,
    user_t *user,
    team_t *team
)
{
    team_subscription_t *subscription;

    for (size_t i = 0; i < VEC_LEN(self->team_subscriptions); i++) {
        subscription = *(team_subscription_t **)
            VEC_AT(self->team_subscriptions, i);
        if (!string_compare(subscription->team_uuid, team->uuid) &&
            !string_compare(subscription->user_uuid, user->uuid))
            return subscription;
    }
    return nullptr;
}
