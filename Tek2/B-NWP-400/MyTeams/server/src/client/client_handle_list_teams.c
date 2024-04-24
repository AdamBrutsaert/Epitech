/*
** EPITECH PROJECT, 2024
** client_handle_list_teams.c
** File description:
** client_handle_list_teams.c
*/

#include "client.h"

void client_handle_list_teams(
    client_t *self,
    __attribute__((unused)) cl_list_teams_packet_t *packet
)
{
    sv_list_teams_packet_t res;

    res.type = PACKET_TYPE_SV_LIST_TEAMS;
    res.teams = self->state->teams;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
}
