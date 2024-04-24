/*
** EPITECH PROJECT, 2024
** state_add_subscription.c
** File description:
** state_add_subscription.c
*/

#include "state.h"

void state_add_subscription(state_t *self, team_subscription_t *subscription)
{
    vec_push_back(self->team_subscriptions, &subscription);
}
