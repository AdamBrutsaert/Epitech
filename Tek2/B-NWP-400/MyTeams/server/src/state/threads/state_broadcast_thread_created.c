/*
** EPITECH PROJECT, 2024
** state_broadcast_thread_created.c
** File description:
** state_broadcast_thread_created.c
*/

#include "state.h"

void state_broadcast_thread_created(state_t *self, thread_t *thread)
{
    sv_create_thread_packet_t res;
    team_subscription_t *sub;
    channel_t *channel = state_get_channel_by_uuid(self, thread->channel_uuid);
    user_t *user;

    res.type = PACKET_TYPE_SV_CREATE_THREAD;
    res.thread = thread;
    if (channel == nullptr)
        return;
    for (size_t i = 0; i < VEC_LEN(self->team_subscriptions); i++) {
        sub = *(team_subscription_t **)VEC_AT(self->team_subscriptions, i);
        if (string_compare(sub->team_uuid, channel->team_uuid) != 0)
            continue;
        user = state_get_user_by_uuid(self, sub->user_uuid);
        if (user == nullptr)
            continue;
        state_send_packet_to_user(self, user, (cl_sv_packet_t *)&res);
    }
}
