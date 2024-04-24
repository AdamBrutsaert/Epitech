/*
** EPITECH PROJECT, 2024
** state_broadcast_channel_created.c
** File description:
** state_broadcast_channel_created.c
*/

#include "state.h"

void state_broadcast_channel_created(state_t *self, channel_t *channel)
{
    sv_create_channel_packet_t res;
    team_subscription_t *sub;
    team_t *team = state_get_team_by_uuid(self, channel->team_uuid);
    user_t *user;

    res.type = PACKET_TYPE_SV_CREATE_CHANNEL;
    res.channel = channel;
    if (team == nullptr)
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
