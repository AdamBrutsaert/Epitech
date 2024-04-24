/*
** EPITECH PROJECT, 2024
** cli_handle_command_logout.c
** File description:
** cli_handle_command_logout.c
*/

#include "cli.h"

#include <stdio.h>

void cli_handle_command_logout(cli_t *self, command_t *cmd)
{
    cl_user_logged_out_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 0) {
        printf("Usage: /logout\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_USER_LOGGED_OUT;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}
