/*
** EPITECH PROJECT, 2024
** client_handle_get_team_info.c
** File description:
** client_handle_get_team_info.c
*/

#include "client.h"

void client_handle_get_team_info(
    client_t *self,
    cl_get_team_info_packet_t *packet
)
{
    team_t *team = state_get_team_by_uuid(self->state, packet->team_uuid);
    sv_error_unknown_team_packet_t err;
    sv_get_team_info_packet_t res;

    if (team == nullptr) {
        err.type = PACKET_TYPE_SV_ERROR_UNKNOWN_TEAM;
        err.uuid = packet->team_uuid;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&err);
        return;
    }
    res.type = PACKET_TYPE_SV_GET_TEAM_INFO;
    res.team = team;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
}
