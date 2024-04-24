/*
** EPITECH PROJECT, 2024
** client_handle_create_team.c
** File description:
** client_handle_create_team.c
*/

#include "client.h"

#include "myteams/logging_server.h"

void client_handle_create_team(client_t *self, cl_create_team_packet_t *packet)
{
    team_t *team = state_get_team_by_name(self->state, packet->name);
    sv_error_already_exist_packet_t err;
    sv_created_team_successfully_packet_t res;

    if (team != nullptr) {
        err.type = PACKET_TYPE_SV_ERROR_ALREADY_EXIST;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&err);
        return;
    }
    team = team_create(packet->name, packet->description);
    state_add_team(self->state, team);
    server_event_team_created(STRING_CDATA(team->uuid),
        STRING_CDATA(team->name), STRING_CDATA(self->user->uuid));
    res.type = PACKET_TYPE_SV_CREATED_TEAM_SUCCESSFULLY;
    res.team = team;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
    state_broadcast_team_created(self->state, team);
}
