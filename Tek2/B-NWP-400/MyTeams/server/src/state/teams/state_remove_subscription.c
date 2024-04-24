/*
** EPITECH PROJECT, 2024
** state_remove_subscription.c
** File description:
** state_remove_subscription.c
*/

#include "state.h"

void state_remove_subscription(
    state_t *self,
    user_t *user,
    team_t *team
)
{
    team_subscription_t *sub;

    for (size_t i = 0; i < VEC_LEN(self->team_subscriptions); i++) {
        sub = *(team_subscription_t **)VEC_AT(self->team_subscriptions, i);
        if (!string_compare(sub->team_uuid, team->uuid) &&
            !string_compare(sub->user_uuid, user->uuid)) {
            team_subscription_destroy(sub);
            vec_remove(self->team_subscriptions, i);
            return;
        }
    }
}
