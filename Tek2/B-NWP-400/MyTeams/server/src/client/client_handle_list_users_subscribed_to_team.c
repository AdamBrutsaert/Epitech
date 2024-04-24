/*
** EPITECH PROJECT, 2024
** client_handle_list_users_subscribed_to_team.c
** File description:
** client_handle_list_users_subscribed_to_team.c
*/

#include "client.h"

static team_t *get_team_or_error(
    client_t *self,
    cl_list_users_subscribed_to_team_packet_t *packet
)
{
    team_t *team = state_get_team_by_uuid(self->state, packet->uuid);
    sv_error_unknown_team_packet_t err;

    if (team == nullptr) {
        err.type = PACKET_TYPE_SV_ERROR_UNKNOWN_TEAM;
        err.uuid = packet->uuid;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&err);
    }
    return team;
}

static void send_unauthorized(client_t *self)
{
    sv_error_unauthorized_packet_t err;

    err.type = PACKET_TYPE_SV_ERROR_UNAUTHORIZED;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&err);
}

void client_handle_list_users_subscribed_to_team(
    client_t *self,
    cl_list_users_subscribed_to_team_packet_t *packet
)
{
    team_t *team = get_team_or_error(self, packet);
    sv_list_users_subscribed_to_team_packet_t res;

    if (team == nullptr)
        return;
    if (!state_is_user_subscribed(self->state, self->user, team)) {
        send_unauthorized(self);
        return;
    }
    res.type = PACKET_TYPE_SV_LIST_USERS_SUBSCRIBED_TO_TEAM;
    res.users = state_get_users_subscribed_to_team(self->state, team);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
    vec_destroy(res.users);
}
