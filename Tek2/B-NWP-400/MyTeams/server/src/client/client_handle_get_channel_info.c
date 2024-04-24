/*
** EPITECH PROJECT, 2024
** client_handle_get_channel_info.c
** File description:
** client_handle_get_channel_info.c
*/

#include "client.h"

static team_t *get_team_or_error(
    client_t *self,
    cl_get_channel_info_packet_t *packet
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

static channel_t *get_channel_or_error(
    client_t *self,
    cl_get_channel_info_packet_t *packet,
    team_t *team
)
{
    channel_t *channel = state_get_channel_by_uuid(self->state,
        packet->channel_uuid);
    sv_error_unknown_channel_packet_t err;

    if (channel == nullptr
        || string_compare(packet->team_uuid, team->uuid) != 0) {
        err.type = PACKET_TYPE_SV_ERROR_UNKNOWN_CHANNEL;
        err.uuid = packet->channel_uuid;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&err);
        return nullptr;
    }
    return channel;
}

void client_handle_get_channel_info(
    client_t *self,
    cl_get_channel_info_packet_t *packet
)
{
    team_t *team = get_team_or_error(self, packet);
    channel_t *channel;
    sv_get_channel_info_packet_t res;

    if (team == nullptr)
        return;
    channel = get_channel_or_error(self, packet, team);
    if (channel == nullptr)
        return;
    res.type = PACKET_TYPE_SV_GET_CHANNEL_INFO;
    res.channel = channel;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
}
