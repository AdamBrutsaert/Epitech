/*
** EPITECH PROJECT, 2024
** client_handle_list_subscribed_teams.c
** File description:
** client_handle_list_subscribed_teams.c
*/

#include "client.h"

void client_handle_list_subscribed_teams(
    client_t *self,
    __attribute__((unused)) cl_list_subscribed_teams_packet_t *packet
)
{
    vec_t *teams = state_get_subscribed_teams(self->state, self->user);
    sv_list_subscribed_teams_packet_t res;

    res.type = PACKET_TYPE_SV_LIST_SUBSCRIBED_TEAMS;
    res.teams = teams;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&res);
    vec_destroy(teams);
}
