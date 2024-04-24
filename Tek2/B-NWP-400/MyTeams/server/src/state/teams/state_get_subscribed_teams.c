/*
** EPITECH PROJECT, 2024
** state_get_subscribed_teams.c
** File description:
** state_get_subscribed_teams.c
*/

#include "state.h"

vec_t *state_get_subscribed_teams(state_t *self, user_t *user)
{
    vec_t *teams = vec_create(sizeof(team_t *));
    team_subscription_t *sub;
    team_t *team;

    for (size_t i = 0; i < VEC_LEN(self->team_subscriptions); i++) {
        sub = *(team_subscription_t **)VEC_AT(self->team_subscriptions, i);
        team = state_get_team_by_uuid(self, sub->team_uuid);
        if (!string_compare(sub->user_uuid, user->uuid) && team != nullptr)
            vec_push_back(teams, &team);
    }
    return teams;
}
