/*
** EPITECH PROJECT, 2024
** cli_handle_command_send.c
** File description:
** cli_handle_command_send.c
*/

#include "cli.h"

#include <stdio.h>

void cli_handle_command_send(cli_t *self, command_t *cmd)
{
    cl_send_private_message_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 2) {
        printf("Usage: /send [\"user_uuid\"] [\"message_body\"]\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_SEND_PRIVATE_MESSAGE;
    packet.to_uuid = *(string_t **)VEC_AT(cmd->arguments, 0);
    packet.message = *(string_t **)VEC_AT(cmd->arguments, 1);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}
