/*
** EPITECH PROJECT, 2024
** cli_handle_command_subscribe.c
** File description:
** cli_handle_command_subscribe.c
*/

#include "cli.h"

#include <stdio.h>

void cli_handle_command_subscribe(cli_t *self, command_t *cmd)
{
    cl_subscribe_to_team_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 1) {
        printf("Usage: /subscribe [\"team_uuid\"]\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_SUBSCRIBE_TO_TEAM;
    packet.uuid = *(string_t **)VEC_AT(cmd->arguments, 0);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}
