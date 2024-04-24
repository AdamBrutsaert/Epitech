/*
** EPITECH PROJECT, 2024
** client_handle_packets.c
** File description:
** client_handle_packets.c
*/

#include "client.h"

#include <stdio.h>

static const packet_handler_t PACKET_HANDLERS[PACKET_TYPE_COUNT] = {
    [PACKET_TYPE_CL_USER_LOGGED_IN] =
    {false, (void *)client_handle_user_logged_in},
    [PACKET_TYPE_CL_USER_LOGGED_OUT] =
    {true, (void *)client_handle_user_logged_out},

    [PACKET_TYPE_CL_SEND_PRIVATE_MESSAGE] =
    {true, (void *)client_handle_send_private_message},
    [PACKET_TYPE_CL_GET_ALL_PRIVATE_MESSAGES] =
    {true, (void *)client_handle_get_all_private_messages},
    [PACKET_TYPE_CL_GET_USER] =
    {true, (void *)client_handle_get_user},
    [PACKET_TYPE_CL_GET_ALL_USERS] =
    {true, (void *)client_handle_get_all_users},

    [PACKET_TYPE_CL_SUBSCRIBE_TO_TEAM] =
    {true, (void *)client_handle_subscribe_to_team},
    [PACKET_TYPE_CL_UNSUBSCRIBE_FROM_TEAM] =
    {true, (void *)client_handle_unsubscribe_from_team},
    [PACKET_TYPE_CL_LIST_SUBSCRIBED_TEAMS] =
    {true, (void *)client_handle_list_subscribed_teams},
    [PACKET_TYPE_CL_LIST_USERS_SUBSCRIBED_TO_TEAM] =
    {true, (void *)client_handle_list_users_subscribed_to_team},

    [PACKET_TYPE_CL_CREATE_TEAM] =
    {true, (void *)client_handle_create_team},
    [PACKET_TYPE_CL_CREATE_CHANNEL] =
    {true, (void *)client_handle_create_channel},
    [PACKET_TYPE_CL_CREATE_THREAD] =
    {true, (void *)client_handle_create_thread},
    [PACKET_TYPE_CL_CREATE_REPLY] =
    {true, (void *)client_handle_create_reply},

    [PACKET_TYPE_CL_LIST_TEAMS] =
    {true, (void *)client_handle_list_teams},
    [PACKET_TYPE_CL_LIST_CHANNELS] =
    {true, (void *)client_handle_list_channels},
    [PACKET_TYPE_CL_LIST_THREADS] =
    {true, (void *)client_handle_list_threads},
    [PACKET_TYPE_CL_LIST_REPLIES] =
    {true, (void *)client_handle_list_replies},

    [PACKET_TYPE_CL_GET_CURRENT_USER_INFO] =
    {true, (void *)client_handle_get_current_user_info},
    [PACKET_TYPE_CL_GET_TEAM_INFO] =
    {true, (void *)client_handle_get_team_info},
    [PACKET_TYPE_CL_GET_CHANNEL_INFO] =
    {true, (void *)client_handle_get_channel_info},
    [PACKET_TYPE_CL_GET_THREAD_INFO] =
    {true, (void *)client_handle_get_thread_info},
};

static bool check_login(client_t *self, packet_type_t type)
{
    sv_error_unauthorized_packet_t packet;

    if (self->user == NULL) {
        printf("[client] Packet of type %hhu requires login!\n", type);
        packet.type = PACKET_TYPE_SV_ERROR_UNAUTHORIZED;
        stream_send_packet(self->stream, (cl_sv_packet_t *)&packet);
        return false;
    }
    return true;
}

static void process_packet(client_t *self, packet_type_t type)
{
    cl_sv_packet_t *packet;

    if (type == PACKET_TYPE_INVALID || PACKET_HANDLERS[type].handler == NULL) {
        stream_discard_packet(self->stream);
        printf("[client] Discarding packet type %hhu\n", type);
        return;
    }
    if (!stream_pop_packet(self->stream, &packet)) {
        stream_discard_packet(self->stream);
        printf("[client] Failed to pop packet type %hhu\n", type);
        printf("[client] Packet might be corrupted\n");
        return;
    }
    if (PACKET_HANDLERS[type].require_login && !check_login(self, type)) {
        cl_sv_packet_destroy(packet);
        return;
    }
    PACKET_HANDLERS[type].handler(self, packet);
    cl_sv_packet_destroy(packet);
}

void client_handle_packets(client_t *self)
{
    while (STREAM_HAS_PACKET(self->stream))
        process_packet(self, stream_peek_packet_type(self->stream));
}
