/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_list_subscribed_teams.c
** File description:
** cli_handle_packet_sv_list_subscribed_teams.c
*/

#include "cli.h"

#include "protocol/entities/team.h"
#include "myteams/logging_client.h"

void cli_handle_packet_sv_list_subscribed_teams(
    __attribute__((unused)) cli_t *self,
    sv_list_subscribed_teams_packet_t *packet
)
{
    team_t *team;

    for (size_t i = 0; i < VEC_LEN(packet->teams); i++) {
        team = *(team_t **)VEC_AT(packet->teams, i);
        client_print_teams(
            STRING_CDATA(team->uuid),
            STRING_CDATA(team->name),
            STRING_CDATA(team->description)
        );
    }
}
