/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_create_team.c
** File description:
** cli_handle_packet_sv_create_team.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_create_team(
    __attribute__((unused)) cli_t *self,
    sv_create_team_packet_t *packet
)
{
    client_event_team_created(
        STRING_CDATA(packet->team->uuid),
        STRING_CDATA(packet->team->name),
        STRING_CDATA(packet->team->description)
    );
}
