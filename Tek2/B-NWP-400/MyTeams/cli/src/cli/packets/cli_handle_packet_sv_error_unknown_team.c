/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_error_unknown_team.c
** File description:
** cli_handle_packet_sv_error_unknown_team.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_error_unknown_team(
    __attribute__((unused)) cli_t *self,
    sv_error_unknown_team_packet_t *packet
)
{
    client_error_unknown_team(STRING_CDATA(packet->uuid));
}
