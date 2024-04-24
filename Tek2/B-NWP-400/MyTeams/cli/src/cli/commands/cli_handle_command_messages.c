/*
** EPITECH PROJECT, 2024
** cli_handle_command_messages.c
** File description:
** cli_handle_command_messages.c
*/

#include "cli.h"

#include <stdio.h>

void cli_handle_command_messages(cli_t *self, command_t *cmd)
{
    cl_get_all_private_messages_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 1) {
        printf("Usage: /messages [\"user_uuid\"]\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_GET_ALL_PRIVATE_MESSAGES;
    packet.uuid = *(string_t **)VEC_AT(cmd->arguments, 0);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}
