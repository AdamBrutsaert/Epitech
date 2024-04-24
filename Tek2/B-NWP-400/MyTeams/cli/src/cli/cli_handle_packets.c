/*
** EPITECH PROJECT, 2024
** cli_handle_packets.c
** File description:
** cli_handle_packets.c
*/

#include "cli.h"

#include <stdio.h>

static const packet_handler_t HANDLERS[PACKET_TYPE_COUNT] = {
    [PACKET_TYPE_SV_USER_LOGGED_IN] =
    (void *)cli_handle_packet_sv_user_logged_in,
    [PACKET_TYPE_SV_USER_LOGGED_OUT] =
    (void *)cli_handle_packet_sv_user_logged_out,
    [PACKET_TYPE_SV_SEND_PRIVATE_MESSAGE] =
    (void *)cli_handle_packet_sv_send_private_message,
    [PACKET_TYPE_SV_GET_ALL_PRIVATE_MESSAGES] =
    (void *)cli_handle_packet_sv_get_all_private_messages,
    [PACKET_TYPE_SV_GET_USER] =
    (void *)cli_handle_packet_sv_get_user,
    [PACKET_TYPE_SV_GET_ALL_USERS] =
    (void *)cli_handle_packet_sv_get_all_users,

    [PACKET_TYPE_SV_SUBSCRIBE_TO_TEAM] =
    (void *)cli_handle_packet_sv_subscribe_to_team,
    [PACKET_TYPE_SV_UNSUBSCRIBE_FROM_TEAM] =
    (void *)cli_handle_packet_sv_unsubscribe_from_team,
    [PACKET_TYPE_SV_LIST_SUBSCRIBED_TEAMS] =
    (void *)cli_handle_packet_sv_list_subscribed_teams,
    [PACKET_TYPE_SV_LIST_USERS_SUBSCRIBED_TO_TEAM] =
    (void *)cli_handle_packet_sv_list_users_subscribed_to_team,

    [PACKET_TYPE_SV_CREATE_TEAM] =
    (void *)cli_handle_packet_sv_create_team,
    [PACKET_TYPE_SV_CREATED_TEAM_SUCCESSFULLY] =
    (void *)cli_handle_packet_sv_created_team_successfully,
    [PACKET_TYPE_SV_CREATE_CHANNEL] =
    (void *)cli_handle_packet_sv_create_channel,
    [PACKET_TYPE_SV_CREATED_CHANNEL_SUCCESSFULLY] =
    (void *)cli_handle_packet_sv_created_channel_successfully,
    [PACKET_TYPE_SV_CREATE_THREAD] =
    (void *)cli_handle_packet_sv_create_thread,
    [PACKET_TYPE_SV_CREATED_THREAD_SUCCESSFULLY] =
    (void *)cli_handle_packet_sv_created_thread_successfully,
    [PACKET_TYPE_SV_CREATE_REPLY] =
    (void *)cli_handle_packet_sv_create_reply,
    [PACKET_TYPE_SV_CREATED_REPLY_SUCCESSFULLY] =
    (void *)cli_handle_packet_sv_created_reply_successfully,

    [PACKET_TYPE_SV_LIST_TEAMS] =
    (void *)cli_handle_packet_sv_list_teams,
    [PACKET_TYPE_SV_LIST_CHANNELS] =
    (void *)cli_handle_packet_sv_list_channels,
    [PACKET_TYPE_SV_LIST_THREADS] =
    (void *)cli_handle_packet_sv_list_threads,
    [PACKET_TYPE_SV_LIST_REPLIES] =
    (void *)cli_handle_packet_sv_list_replies,

    [PACKET_TYPE_SV_GET_CURRENT_USER_INFO] =
    (void *)cli_handle_packet_sv_get_current_user_info,
    [PACKET_TYPE_SV_GET_TEAM_INFO] =
    (void *)cli_handle_packet_sv_get_team_info,
    [PACKET_TYPE_SV_GET_CHANNEL_INFO] =
    (void *)cli_handle_packet_sv_get_channel_info,
    [PACKET_TYPE_SV_GET_THREAD_INFO] =
    (void *)cli_handle_packet_sv_get_thread_info,

    [PACKET_TYPE_SV_ERROR_UNKNOWN_TEAM] =
    (void *)cli_handle_packet_sv_error_unknown_team,
    [PACKET_TYPE_SV_ERROR_UNKNOWN_CHANNEL] =
    (void *)cli_handle_packet_sv_error_unknown_channel,
    [PACKET_TYPE_SV_ERROR_UNKNOWN_THREAD] =
    (void *)cli_handle_packet_sv_error_unknown_thread,
    [PACKET_TYPE_SV_ERROR_UNKNOWN_USER] =
    (void *)cli_handle_packet_sv_error_unknown_user,
    [PACKET_TYPE_SV_ERROR_UNAUTHORIZED] =
    (void *)cli_handle_packet_sv_error_unauthorized,
    [PACKET_TYPE_SV_ERROR_ALREADY_EXIST] =
    (void *)cli_handle_packet_sv_error_already_exist,

    [PACKET_TYPE_SV_DISCONNECTION_SUCCESS] =
    (void *)cli_handle_packet_sv_disconnection_success,
};

static void process_packet(cli_t *self, packet_type_t type)
{
    cl_sv_packet_t *packet;

    if (type == PACKET_TYPE_INVALID || HANDLERS[type] == NULL) {
        stream_discard_packet(self->stream);
        printf("[cli] Discarding packet type %hhu\n", type);
        return;
    }
    if (!stream_pop_packet(self->stream, &packet)) {
        stream_discard_packet(self->stream);
        printf("[cli] Failed to pop packet type %hhu\n", type);
        printf("[cli] Packet might be corrupted\n");
        return;
    }
    HANDLERS[type](self, packet);
    cl_sv_packet_destroy(packet);
}

void cli_handle_packets(cli_t *self)
{
    while (STREAM_HAS_PACKET(self->stream))
        process_packet(self, stream_peek_packet_type(self->stream));
}
