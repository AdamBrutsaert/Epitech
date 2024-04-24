/*
** EPITECH PROJECT, 2024
** client_handle_create_reply.c
** File description:
** client_handle_create_reply.c
*/

#include "client.h"

#include "myteams/logging_server.h"

static team_t *get_team_or_error(
    client_t *self,
    cl_create_reply_packet_t *packet
)
{
    sv_error_unknown_team_packet_t err;
    sv_error_unauthorized_packet_t err_unauth;
    team_t *team = state_get_team_by_uuid(self->state, packet->team_uuid);

    if (team == nullptr) {
        err.type = PACKET_TYPE_SV_ERROR_UNKNOWN_TEAM;
        err.uuid = packet->team_uuid;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&err);
        return nullptr;
    }
    if (!state_is_user_subscribed(self->state, self->user, team)) {
        err_unauth.type = PACKET_TYPE_SV_ERROR_UNAUTHORIZED;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&err_unauth);
        return nullptr;
    }
    return team;
}

static channel_t *get_channel_or_error(
    client_t *self,
    cl_create_reply_packet_t *packet,
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

static thread_t *get_thread_or_error(
    client_t *self,
    cl_create_reply_packet_t *packet,
    channel_t *channel
)
{
    thread_t *thread = state_get_thread_by_uuid(self->state,
        packet->thread_uuid);
    sv_error_unknown_thread_packet_t err;

    if (thread == nullptr
        || string_compare(packet->channel_uuid, channel->uuid) != 0) {
        err.type = PACKET_TYPE_SV_ERROR_UNKNOWN_THREAD;
        err.uuid = packet->thread_uuid;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&err);
        return nullptr;
    }
    return thread;
}

static reply_t *create_reply(
    client_t *self,
    cl_create_reply_packet_t *packet,
    thread_t *thread
)
{
    reply_t *reply = reply_create(thread->uuid, self->user->uuid, time(NULL),
        packet->body);

    state_add_reply(self->state, reply);
    return reply;
}

static void send_confirmation(
    client_t *self,
    reply_t *reply
)
{
    sv_created_reply_successfully_packet_t res;

    res.type = PACKET_TYPE_SV_CREATED_REPLY_SUCCESSFULLY;
    res.reply = reply;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
}

void client_handle_create_reply(
    client_t *self,
    cl_create_reply_packet_t *packet
)
{
    team_t *team = get_team_or_error(self, packet);
    channel_t *channel;
    thread_t *thread;
    reply_t *reply;

    if (team == nullptr)
        return;
    channel = get_channel_or_error(self, packet, team);
    if (channel == nullptr)
        return;
    thread = get_thread_or_error(self, packet, channel);
    if (thread == nullptr)
        return;
    reply = create_reply(self, packet, thread);
    server_event_reply_created(STRING_CDATA(thread->uuid),
        STRING_CDATA(self->user->uuid), STRING_CDATA(reply->body));
    send_confirmation(self, reply);
    state_broadcast_reply_created(self->state, reply);
}
