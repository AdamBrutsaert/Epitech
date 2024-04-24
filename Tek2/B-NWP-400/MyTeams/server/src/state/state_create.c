/*
** EPITECH PROJECT, 2024
** state_create.c
** File description:
** state_create.c
*/

#include "state.h"
#include "my/memory/allocation.h"

state_t *state_create(void)
{
    state_t *self = allocate(sizeof(state_t));

    self->users = vec_create(sizeof(user_t *));
    self->connections = vec_create(sizeof(connection_t *));
    self->messages = vec_create(sizeof(message_t *));
    self->teams = vec_create(sizeof(team_t *));
    self->team_subscriptions = vec_create(sizeof(team_subscription_t *));
    self->channels = vec_create(sizeof(channel_t *));
    self->threads = vec_create(sizeof(thread_t *));
    self->replies = vec_create(sizeof(reply_t *));
    return self;
}
