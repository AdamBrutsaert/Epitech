/*
** EPITECH PROJECT, 2024
** state_broadcast_reply_created.c
** File description:
** state_broadcast_reply_created.c
*/

#include "state.h"

static void do_broadcast(
    state_t *self,
    sv_create_reply_packet_t *res,
    team_t *team
)
{
    team_subscription_t *sub;
    user_t *user;

    for (size_t i = 0; i < VEC_LEN(self->team_subscriptions); i++) {
        sub = *(team_subscription_t **)VEC_AT(self->team_subscriptions, i);
        if (string_compare(sub->team_uuid, team->uuid) != 0)
            continue;
        user = state_get_user_by_uuid(self, sub->user_uuid);
        if (user == nullptr)
            continue;
        state_send_packet_to_user(self, user, (cl_sv_packet_t *)res);
    }
}

void state_broadcast_reply_created(state_t *self, reply_t *reply)
{
    sv_create_reply_packet_t res;
    thread_t *thread = state_get_thread_by_uuid(self, reply->thread_uuid);
    channel_t *channel;

    res.type = PACKET_TYPE_SV_CREATE_REPLY;
    res.reply = reply;
    if (thread == nullptr)
        return;
    channel = state_get_channel_by_uuid(self, thread->channel_uuid);
    if (channel == nullptr)
        return;
    res.team = state_get_team_by_uuid(self, channel->team_uuid);
    if (res.team == nullptr)
        return;
    do_broadcast(self, &res, res.team);
}
