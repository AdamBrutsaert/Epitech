/*
** EPITECH PROJECT, 2024
** cli_handle_command_get_user.c
** File description:
** cli_handle_command_get_user.c
*/

#include "cli.h"
#include <stdio.h>

void cli_handle_get_user_command(cli_t *self, command_t *cmd)
{
    cl_get_user_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 1) {
        printf("Usage: /user <user_uuid>");
        return;
    }
    packet.type = PACKET_TYPE_CL_GET_USER;
    packet.uuid = *(string_t **)VEC_AT(cmd->arguments, 0);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}
