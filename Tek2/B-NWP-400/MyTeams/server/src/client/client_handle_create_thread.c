/*
** EPITECH PROJECT, 2024
** client_handle_create_thread.c
** File description:
** client_handle_create_thread.c
*/

#include "client.h"

#include "myteams/logging_server.h"

static team_t *get_team_or_error(
    client_t *self,
    cl_create_thread_packet_t *packet
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
    cl_create_thread_packet_t *packet,
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

static thread_t *create_thread(
    client_t *self,
    cl_create_thread_packet_t *packet,
    channel_t *channel
)
{
    thread_t *thread = thread_create(&(thread_create_args_t){channel->uuid,
        self->user->uuid, time(NULL), packet->title, packet->body});

    state_add_thread(self->state, thread);
    return thread;
}

void client_handle_create_thread(
    client_t *self,
    cl_create_thread_packet_t *packet
)
{
    team_t *team = get_team_or_error(self, packet);
    channel_t *channel;
    thread_t *thread;
    sv_created_thread_successfully_packet_t res;

    if (team == nullptr)
        return;
    channel = get_channel_or_error(self, packet, team);
    if (channel == nullptr)
        return;
    thread = create_thread(self, packet, channel);
    server_event_thread_created(
        STRING_CDATA(thread->channel_uuid), STRING_CDATA(thread->uuid),
        STRING_CDATA(thread->user_uuid), STRING_CDATA(thread->title),
        STRING_CDATA(thread->body));
    res.type = PACKET_TYPE_SV_CREATED_THREAD_SUCCESSFULLY;
    res.thread = thread;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
    state_broadcast_thread_created(self->state, thread);
}
