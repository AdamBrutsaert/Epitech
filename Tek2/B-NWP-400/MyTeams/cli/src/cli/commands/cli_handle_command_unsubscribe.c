/*
** EPITECH PROJECT, 2024
** cli_handle_command_unsubscribe.c
** File description:
** cli_handle_command_unsubscribe.c
*/

#include "cli.h"

#include <stdio.h>

void cli_handle_command_unsubscribe(cli_t *self, command_t *cmd)
{
    cl_unsubscribe_from_team_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 1) {
        printf("Usage: /unsubscribe [\"team_uuid\"]\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_UNSUBSCRIBE_FROM_TEAM;
    packet.uuid = *(string_t **)VEC_AT(cmd->arguments, 0);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}
