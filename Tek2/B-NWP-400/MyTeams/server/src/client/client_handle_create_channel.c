/*
** EPITECH PROJECT, 2024
** client_handle_create_channel.c
** File description:
** client_handle_create_channel.c
*/

#include "client.h"

#include "myteams/logging_server.h"

static team_t *get_team_or_error(
    client_t *self,
    cl_create_channel_packet_t *packet
)
{
    sv_error_unknown_team_packet_t err;
    team_t *team = state_get_team_by_uuid(self->state, packet->team_uuid);

    if (team == nullptr) {
        err.type = PACKET_TYPE_SV_ERROR_UNKNOWN_TEAM;
        err.uuid = packet->team_uuid;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&err);
    }
    return team;
}

static channel_t *not_get_channel_or_error(
    client_t *self,
    cl_create_channel_packet_t *packet,
    team_t *team
)
{
    sv_error_already_exist_packet_t err;
    channel_t *channel = state_get_channel_by_name(self->state, team,
        packet->name);

    if (channel != nullptr) {
        err.type = PACKET_TYPE_SV_ERROR_ALREADY_EXIST;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&err);
        return channel;
    }
    return channel;
}

static bool check_subscribed_or_error(
    client_t *self,
    team_t *team
)
{
    sv_error_unauthorized_packet_t err;

    if (!state_is_user_subscribed(self->state, self->user, team)) {
        err.type = PACKET_TYPE_SV_ERROR_UNAUTHORIZED;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&err);
        return false;
    }
    return true;
}

void client_handle_create_channel(
    client_t *self,
    cl_create_channel_packet_t *packet
)
{
    team_t *team = get_team_or_error(self, packet);
    channel_t *channel;
    sv_created_channel_successfully_packet_t res;

    if (team == nullptr)
        return;
    if (!check_subscribed_or_error(self, team))
        return;
    channel = not_get_channel_or_error(self, packet, team);
    if (channel != nullptr)
        return;
    channel = channel_create(packet->team_uuid, packet->name,
        packet->description);
    state_add_channel(self->state, channel);
    server_event_channel_created(STRING_CDATA(channel->team_uuid),
        STRING_CDATA(channel->uuid), STRING_CDATA(channel->name));
    res.type = PACKET_TYPE_SV_CREATED_CHANNEL_SUCCESSFULLY;
    res.channel = channel;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
    state_broadcast_channel_created(self->state, channel);
}
