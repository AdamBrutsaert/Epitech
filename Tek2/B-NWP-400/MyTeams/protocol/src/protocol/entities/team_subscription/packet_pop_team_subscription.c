/*
** EPITECH PROJECT, 2024
** packet_pop_team_subscription.c
** File description:
** packet_pop_team_subscription.c
*/

#include "protocol/entities/team_subscription.h"

#include "my/memory/allocation.h"

bool packet_pop_team_subscription(packet_t *self, team_subscription_t **team)
{
    string_t *team_uuid;
    string_t *user_uuid;

    if (!packet_pop_string(self, &user_uuid))
        return false;
    if (!packet_pop_string(self, &team_uuid)) {
        string_destroy(user_uuid);
        return false;
    }
    *team = allocate(sizeof(team_subscription_t));
    **team = (team_subscription_t){team_uuid, user_uuid};
    return true;
}
