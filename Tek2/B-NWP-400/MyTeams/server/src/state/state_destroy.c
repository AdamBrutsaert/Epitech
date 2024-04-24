/*
** EPITECH PROJECT, 2024
** state_destroy.c
** File description:
** state_destroy.c
*/

#include "state.h"

#include "my/memory/allocation.h"

static void destroy_vec_items(state_t *self)
{
    for (size_t i = 0; i < VEC_LEN(self->users); i++)
        user_destroy(*(user_t **)VEC_AT(self->users, i));
    for (size_t i = 0; i < VEC_LEN(self->connections); i++)
        connection_destroy(*(connection_t **)VEC_AT(self->connections, i));
    for (size_t i = 0; i < VEC_LEN(self->messages); i++)
        message_destroy(*(message_t **)VEC_AT(self->messages, i));
    for (size_t i = 0; i < VEC_LEN(self->teams); i++)
        team_destroy(*(team_t **)VEC_AT(self->teams, i));
    for (size_t i = 0; i < VEC_LEN(self->team_subscriptions); i++)
        team_subscription_destroy(*(team_subscription_t **)VEC_AT(
            self->team_subscriptions, i));
    for (size_t i = 0; i < VEC_LEN(self->channels); i++)
        channel_destroy(*(channel_t **)VEC_AT(self->channels, i));
    for (size_t i = 0; i < VEC_LEN(self->threads); i++)
        thread_destroy(*(thread_t **)VEC_AT(self->threads, i));
    for (size_t i = 0; i < VEC_LEN(self->replies); i++)
        reply_destroy(*(reply_t **)VEC_AT(self->replies, i));
}

void state_destroy(state_t *self)
{
    destroy_vec_items(self);
    vec_destroy(self->users);
    vec_destroy(self->connections);
    vec_destroy(self->messages);
    vec_destroy(self->teams);
    vec_destroy(self->team_subscriptions);
    vec_destroy(self->channels);
    vec_destroy(self->threads);
    vec_destroy(self->replies);
    deallocate(self);
}
