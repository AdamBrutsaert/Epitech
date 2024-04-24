/*
** EPITECH PROJECT, 2024
** packet_push_team_subscription.c
** File description:
** packet_push_team_subscription.c
*/

#include "protocol/entities/team_subscription.h"

void packet_push_team_subscription(
    packet_t *self,
    const team_subscription_t *team
)
{
    packet_push_string(self, team->team_uuid);
    packet_push_string(self, team->user_uuid);
}
