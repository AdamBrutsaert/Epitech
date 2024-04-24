/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_unsubscribe_from_team.c
** File description:
** cli_handle_packet_sv_unsubscribe_from_team.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_unsubscribe_from_team(
    __attribute__((unused)) cli_t *self,
    sv_unsubscribe_from_team_packet_t *packet
)
{
    client_print_unsubscribed(
        STRING_CDATA(packet->team_subscription->user_uuid),
        STRING_CDATA(packet->team_subscription->team_uuid)
    );
}
