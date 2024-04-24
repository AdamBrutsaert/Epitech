/*
** EPITECH PROJECT, 2024
** cli_handle_command_login.c
** File description:
** cli_handle_command_login.c
*/

#include "cli.h"

#include <stdio.h>

void cli_handle_command_login(cli_t *self, command_t *cmd)
{
    cl_user_logged_in_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 1) {
        printf("Usage: /login <username>\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_USER_LOGGED_IN;
    packet.name = *(string_t **)VEC_AT(cmd->arguments, 0);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}
