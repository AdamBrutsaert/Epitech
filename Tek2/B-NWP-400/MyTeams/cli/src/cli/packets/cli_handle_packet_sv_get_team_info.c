/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_get_team_info.c
** File description:
** cli_handle_packet_sv_get_team_info.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_get_team_info(
    __attribute__((unused)) cli_t *self,
    sv_get_team_info_packet_t *packet
)
{
    client_print_team(
        STRING_CDATA(packet->team->uuid),
        STRING_CDATA(packet->team->name),
        STRING_CDATA(packet->team->description)
    );
}
