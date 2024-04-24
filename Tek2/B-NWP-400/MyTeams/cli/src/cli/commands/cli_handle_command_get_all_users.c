/*
** EPITECH PROJECT, 2024
** cli_handle_command_get_all_users.c
** File description:
** cli_handle_command_get_all_users.c
*/

#include "cli.h"
#include <stdio.h>

void cli_handle_command_get_all_users(cli_t *self, command_t *cmd)
{
    cl_get_all_users_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 0) {
        printf("Usage: /users");
        return;
    }
    packet.type = PACKET_TYPE_CL_GET_ALL_USERS;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}
