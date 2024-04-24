/*
** EPITECH PROJECT, 2024
** client_handle_subscribe_to_team.c
** File description:
** client_handle_subscribe_to_team.c
*/

#include "client.h"

#include "myteams/logging_server.h"

static team_subscription_t *get_or_create_subscription(
    client_t *self,
    team_t *team
)
{
    team_subscription_t *subscription = state_get_subscription(self->state,
        self->user, team);

    if (subscription == nullptr) {
        subscription = team_subscription_create(team->uuid, self->user->uuid);
        state_add_subscription(self->state, subscription);
    }
    return subscription;
}

void client_handle_subscribe_to_team(
    client_t *self,
    cl_subscribe_to_team_packet_t *packet
)
{
    team_t *team = state_get_team_by_uuid(self->state, packet->uuid);
    team_subscription_t *subscription;
    sv_error_unknown_team_packet_t error;
    sv_subscribe_to_team_packet_t res;

    if (team == nullptr) {
        error.type = PACKET_TYPE_SV_ERROR_UNKNOWN_TEAM;
        error.uuid = packet->uuid;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&error);
        return;
    }
    subscription = get_or_create_subscription(self, team);
    res.type = PACKET_TYPE_SV_SUBSCRIBE_TO_TEAM;
    res.team_subscription = subscription;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
    server_event_user_subscribed(STRING_CDATA(team->uuid),
        STRING_CDATA(self->user->uuid));
}
