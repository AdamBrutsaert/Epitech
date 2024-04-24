/*
** EPITECH PROJECT, 2024
** cli_handle_command_list.c
** File description:
** cli_handle_command_list.c
*/

#include "cli.h"

#include <stdio.h>

static void handle_list_team(cli_t *self, command_t *cmd)
{
    cl_list_teams_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 0) {
        printf("Usage: /list\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_LIST_TEAMS;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

static void handle_list_chanels(cli_t *self, command_t *cmd)
{
    cl_list_channels_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 0) {
        printf("Usage: /list\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_LIST_CHANNELS;
    packet.team_uuid = self->context_team_uuid;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

static void handle_list_threads(cli_t *self, command_t *cmd)
{
    cl_list_threads_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 0) {
        printf("Usage: /list\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_LIST_THREADS;
    packet.team_uuid = self->context_team_uuid;
    packet.channel_uuid = self->context_channel_uuid;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

static void handle_list_replies(cli_t *self, command_t *cmd)
{
    cl_list_replies_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 0) {
        printf("Usage: /list\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_LIST_REPLIES;
    packet.team_uuid = self->context_team_uuid;
    packet.channel_uuid = self->context_channel_uuid;
    packet.thread_uuid = self->context_thread_uuid;
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

void cli_handle_command_list(cli_t *self, command_t *cmd)
{
    if (self->context_team_uuid == nullptr) {
        handle_list_team(self, cmd);
        return;
    }
    if (self->context_channel_uuid == nullptr) {
        handle_list_chanels(self, cmd);
        return;
    }
    if (self->context_thread_uuid == nullptr) {
        handle_list_threads(self, cmd);
        return;
    }
    handle_list_replies(self, cmd);
}
