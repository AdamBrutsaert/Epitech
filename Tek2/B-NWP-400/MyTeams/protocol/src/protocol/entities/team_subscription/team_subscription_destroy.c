/*
** EPITECH PROJECT, 2024
** team_subscription_destroy.c
** File description:
** team_subscription_destroy.c
*/

#include "protocol/entities/team_subscription.h"

#include "my/memory/allocation.h"

void team_subscription_destroy(team_subscription_t *team_subscription)
{
    string_destroy(team_subscription->team_uuid);
    string_destroy(team_subscription->user_uuid);
    deallocate(team_subscription);
}
