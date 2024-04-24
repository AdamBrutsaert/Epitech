/*
** EPITECH PROJECT, 2024
** cli_handle_command_subscribed.c
** File description:
** cli_handle_command_subscribed.c
*/

#include "cli.h"

#include <stdio.h>

static void handle_list_subscribed_teams(cli_t *self)
{
    cl_list_subscribed_teams_packet_t packet;

    packet.type = PACKET_TYPE_CL_LIST_SUBSCRIBED_TEAMS;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

static void handle_list_users_subscribed_to_team(cli_t *self, command_t *cmd)
{
    cl_list_users_subscribed_to_team_packet_t packet;

    packet.type = PACKET_TYPE_CL_LIST_USERS_SUBSCRIBED_TO_TEAM;
    packet.uuid = *(string_t **)VEC_AT(cmd->arguments, 0);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

void cli_handle_command_subscribed(cli_t *self, command_t *cmd)
{
    if (VEC_LEN(cmd->arguments) == 0) {
        handle_list_subscribed_teams(self);
        return;
    }
    if (VEC_LEN(cmd->arguments) == 1) {
        handle_list_users_subscribed_to_team(self, cmd);
        return;
    }
    printf("Usage: /subscribed ?[\"team_uuid\"]\n");
}
