/*
** EPITECH PROJECT, 2024
** cli_handle_command_create.c
** File description:
** cli_handle_command_create.c
*/

#include "cli.h"

#include <stdio.h>

static void handle_create_team(cli_t *self, command_t *cmd)
{
    cl_create_team_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 2) {
        printf("Usage: /create [\"team_name\"] [\"team_description\"]\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_CREATE_TEAM;
    packet.name = *(string_t **)VEC_AT(cmd->arguments, 0);
    packet.description = *(string_t **)VEC_AT(cmd->arguments, 1);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

static void handle_create_channel(cli_t *self, command_t *cmd)
{
    cl_create_channel_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 2) {
        printf("Usage: /create [\"channel_name\"] [\"channel_description\"]"
            "\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_CREATE_CHANNEL;
    packet.team_uuid = self->context_team_uuid;
    packet.name = *(string_t **)VEC_AT(cmd->arguments, 0);
    packet.description = *(string_t **)VEC_AT(cmd->arguments, 1);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

static void handle_create_thread(cli_t *self, command_t *cmd)
{
    cl_create_thread_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 2) {
        printf("Usage: /create [\"thread_title\"] [\"thread_message\"]\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_CREATE_THREAD;
    packet.team_uuid = self->context_team_uuid;
    packet.channel_uuid = self->context_channel_uuid;
    packet.title = *(string_t **)VEC_AT(cmd->arguments, 0);
    packet.body = *(string_t **)VEC_AT(cmd->arguments, 1);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

static void handle_create_reply(cli_t *self, command_t *cmd)
{
    cl_create_reply_packet_t packet;

    if (VEC_LEN(cmd->arguments) != 1) {
        printf("Usage: /create [\"comment_body\"]\n");
        return;
    }
    packet.type = PACKET_TYPE_CL_CREATE_REPLY;
    packet.team_uuid = self->context_team_uuid;
    packet.channel_uuid = self->context_channel_uuid;
    packet.thread_uuid = self->context_thread_uuid;
    packet.body = *(string_t **)VEC_AT(cmd->arguments, 0);
    stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
}

void cli_handle_command_create(cli_t *self, command_t *cmd)
{
    if (self->context_team_uuid == nullptr) {
        handle_create_team(self, cmd);
        return;
    }
    if (self->context_channel_uuid == nullptr) {
        handle_create_channel(self, cmd);
        return;
    }
    if (self->context_thread_uuid == nullptr) {
        handle_create_thread(self, cmd);
        return;
    }
    handle_create_reply(self, cmd);
}
