/*
** EPITECH PROJECT, 2024
** client_handle_list_channels.c
** File description:
** client_handle_list_channels.c
*/

#include "client.h"

static team_t *get_team_or_error(
    client_t *self,
    cl_list_channels_packet_t *packet
)
{
    team_t *team = state_get_team_by_uuid(self->state, packet->team_uuid);
    sv_error_unknown_team_packet_t err;
    sv_error_unauthorized_packet_t err2;

    if (team == nullptr) {
        err.type = PACKET_TYPE_SV_ERROR_UNKNOWN_TEAM;
        err.uuid = packet->team_uuid;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&err);
        return nullptr;
    }
    if (!state_is_user_subscribed(self->state, self->user, team)) {
        err2.type = PACKET_TYPE_SV_ERROR_UNAUTHORIZED;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&err2);
        return nullptr;
    }
    return team;
}

void client_handle_list_channels(
    client_t *self,
    cl_list_channels_packet_t *packet
)
{
    team_t *team = get_team_or_error(self, packet);
    vec_t *channels;
    sv_list_channels_packet_t res;

    if (team == nullptr)
        return;
    channels = state_get_channels_of_team(self->state, team);
    res.type = PACKET_TYPE_SV_LIST_CHANNELS;
    res.channels = channels;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
    vec_destroy(channels);
}
