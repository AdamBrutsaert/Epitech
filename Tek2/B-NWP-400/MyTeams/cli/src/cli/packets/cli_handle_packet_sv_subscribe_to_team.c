/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_subscribe_to_team.c
** File description:
** cli_handle_packet_sv_subscribe_to_team.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_subscribe_to_team(
    __attribute__((unused)) cli_t *self,
    sv_subscribe_to_team_packet_t *packet
)
{
    client_print_subscribed(
        STRING_CDATA(packet->team_subscription->user_uuid),
        STRING_CDATA(packet->team_subscription->team_uuid)
    );
}
