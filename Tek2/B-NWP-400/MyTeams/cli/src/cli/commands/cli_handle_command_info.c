/*
** EPITECH PROJECT, 2024
** cli_handle_command_info.c
** File description:
** cli_handle_command_info.c
*/

#include "cli.h"

#include <stdio.h>

static void handle_info_user(cli_t *self, command_t *cmd)
{
    cl_get_current_user_info_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 0) {
        printf("Usage: /info\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_GET_CURRENT_USER_INFO;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

static void handle_info_team(cli_t *self, command_t *cmd)
{
    cl_get_team_info_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 0) {
        printf("Usage: /info\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_GET_TEAM_INFO;
    packet.team_uuid = self->context_team_uuid;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

static void handle_info_channel(cli_t *self, command_t *cmd)
{
    cl_get_channel_info_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 0) {
        printf("Usage: /info\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_GET_CHANNEL_INFO;
    packet.team_uuid = self->context_team_uuid;
    packet.channel_uuid = self->context_channel_uuid;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

static void handle_info_thread(cli_t *self, command_t *cmd)
{
    cl_get_thread_info_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 0) {
        printf("Usage: /info\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_GET_THREAD_INFO;
    packet.team_uuid = self->context_team_uuid;
    packet.channel_uuid = self->context_channel_uuid;
    packet.thread_uuid = self->context_thread_uuid;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

void cli_handle_command_info(cli_t *self, command_t *cmd)
{
    if (self->context_team_uuid == nullptr) {
        handle_info_user(self, cmd);
        return;
    }
    if (self->context_channel_uuid == nullptr) {
        handle_info_team(self, cmd);
        return;
    }
    if (self->context_thread_uuid == nullptr) {
        handle_info_channel(self, cmd);
        return;
    }
    handle_info_thread(self, cmd);
}
