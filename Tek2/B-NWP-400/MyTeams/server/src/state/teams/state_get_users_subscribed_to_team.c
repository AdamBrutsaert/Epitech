/*
** EPITECH PROJECT, 2024
** state_get_users_subscribed_to_team.c
** File description:
** state_get_users_subscribed_to_team.c
*/

#include "state.h"

vec_t *state_get_users_subscribed_to_team(state_t *self, team_t *team)
{
    vec_t *users = vec_create(sizeof(user_t *));
    team_subscription_t *sub;
    user_t *user;

    for (size_t i = 0; i < VEC_LEN(self->team_subscriptions); i++) {
        sub = *(team_subscription_t **)VEC_AT(self->team_subscriptions, i);
        user = state_get_user_by_uuid(self, sub->user_uuid);
        if (!string_compare(sub->team_uuid, team->uuid) && user != nullptr)
            vec_push_back(users, &user);
    }
    return users;
}
