/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_created_team_successfully.c
** File description:
** cli_handle_packet_sv_created_team_successfully.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_created_team_successfully(
    __attribute__((unused)) cli_t *self,
    sv_created_team_successfully_packet_t *packet
)
{
    client_print_team_created(
        STRING_CDATA(packet->team->uuid),
        STRING_CDATA(packet->team->name),
        STRING_CDATA(packet->team->description)
    );
}
