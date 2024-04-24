/*
** EPITECH PROJECT, 2024
** cl_sv_packet_destroy.c
** File description:
** cl_sv_packet_destroy.c
*/

#include "protocol/codec.h"

#include <stdio.h>

static const cl_sv_packet_destroyer_t handlers[PACKET_TYPE_COUNT] = {
    [PACKET_TYPE_CL_USER_LOGGED_IN] =
    (cl_sv_packet_destroyer_t)cl_user_logged_in_packet_destroy,
    [PACKET_TYPE_SV_USER_LOGGED_IN] =
    (cl_sv_packet_destroyer_t)sv_user_logged_in_packet_destroy,
    [PACKET_TYPE_CL_USER_LOGGED_OUT] =
    (cl_sv_packet_destroyer_t)cl_user_logged_out_packet_destroy,
    [PACKET_TYPE_SV_USER_LOGGED_OUT] =
    (cl_sv_packet_destroyer_t)sv_user_logged_out_packet_destroy,
    [PACKET_TYPE_CL_SEND_PRIVATE_MESSAGE] =
    (cl_sv_packet_destroyer_t)cl_send_private_message_packet_destroy,
    [PACKET_TYPE_SV_SEND_PRIVATE_MESSAGE] =
    (cl_sv_packet_destroyer_t)sv_send_private_message_packet_destroy,
    [PACKET_TYPE_CL_GET_ALL_PRIVATE_MESSAGES] =
    (cl_sv_packet_destroyer_t)cl_get_all_private_messages_packet_destroy,
    [PACKET_TYPE_SV_GET_ALL_PRIVATE_MESSAGES] =
    (cl_sv_packet_destroyer_t)sv_get_all_private_messages_packet_destroy,
    [PACKET_TYPE_CL_GET_USER] =
    (cl_sv_packet_destroyer_t)cl_get_user_packet_destroy,
    [PACKET_TYPE_SV_GET_USER] =
    (cl_sv_packet_destroyer_t)sv_get_user_packet_destroy,
    [PACKET_TYPE_CL_GET_ALL_USERS] =
    (cl_sv_packet_destroyer_t)cl_get_all_users_packet_destroy,
    [PACKET_TYPE_SV_GET_ALL_USERS] =
    (cl_sv_packet_destroyer_t)sv_get_all_users_packet_destroy,

    [PACKET_TYPE_CL_SUBSCRIBE_TO_TEAM] =
    (cl_sv_packet_destroyer_t)cl_subscribe_to_team_packet_destroy,
    [PACKET_TYPE_SV_SUBSCRIBE_TO_TEAM] =
    (cl_sv_packet_destroyer_t)sv_subscribe_to_team_packet_destroy,
    [PACKET_TYPE_CL_UNSUBSCRIBE_FROM_TEAM] =
    (cl_sv_packet_destroyer_t)cl_unsubscribe_from_team_packet_destroy,
    [PACKET_TYPE_SV_UNSUBSCRIBE_FROM_TEAM] =
    (cl_sv_packet_destroyer_t)sv_unsubscribe_from_team_packet_destroy,
    [PACKET_TYPE_CL_LIST_SUBSCRIBED_TEAMS] =
    (cl_sv_packet_destroyer_t)cl_list_subscribed_teams_packet_destroy,
    [PACKET_TYPE_SV_LIST_SUBSCRIBED_TEAMS] =
    (cl_sv_packet_destroyer_t)sv_list_subscribed_teams_packet_destroy,
    [PACKET_TYPE_CL_LIST_USERS_SUBSCRIBED_TO_TEAM] =
    (cl_sv_packet_destroyer_t)cl_list_users_subscribed_to_team_packet_destroy,
    [PACKET_TYPE_SV_LIST_USERS_SUBSCRIBED_TO_TEAM] =
    (cl_sv_packet_destroyer_t)sv_list_users_subscribed_to_team_packet_destroy,

    [PACKET_TYPE_CL_CREATE_TEAM] =
    (cl_sv_packet_destroyer_t)cl_create_team_packet_destroy,
    [PACKET_TYPE_SV_CREATE_TEAM] =
    (cl_sv_packet_destroyer_t)sv_create_team_packet_destroy,
    [PACKET_TYPE_SV_CREATED_TEAM_SUCCESSFULLY] =
    (cl_sv_packet_destroyer_t)sv_created_team_successfully_packet_destroy,
    [PACKET_TYPE_CL_CREATE_CHANNEL] =
    (cl_sv_packet_destroyer_t)cl_create_channel_packet_destroy,
    [PACKET_TYPE_SV_CREATE_CHANNEL] =
    (cl_sv_packet_destroyer_t)sv_create_channel_packet_destroy,
    [PACKET_TYPE_SV_CREATED_CHANNEL_SUCCESSFULLY] =
    (cl_sv_packet_destroyer_t)sv_created_channel_successfully_packet_destroy,
    [PACKET_TYPE_CL_CREATE_THREAD] =
    (cl_sv_packet_destroyer_t)cl_create_thread_packet_destroy,
    [PACKET_TYPE_SV_CREATE_THREAD] =
    (cl_sv_packet_destroyer_t)sv_create_thread_packet_destroy,
    [PACKET_TYPE_SV_CREATED_THREAD_SUCCESSFULLY] =
    (cl_sv_packet_destroyer_t)sv_created_thread_successfully_packet_destroy,
    [PACKET_TYPE_CL_CREATE_REPLY] =
    (cl_sv_packet_destroyer_t)cl_create_reply_packet_destroy,
    [PACKET_TYPE_SV_CREATE_REPLY] =
    (cl_sv_packet_destroyer_t)sv_create_reply_packet_destroy,
    [PACKET_TYPE_SV_CREATED_REPLY_SUCCESSFULLY] =
    (cl_sv_packet_destroyer_t)sv_created_reply_successfully_packet_destroy,

    [PACKET_TYPE_CL_LIST_TEAMS] =
    (cl_sv_packet_destroyer_t)cl_list_teams_packet_destroy,
    [PACKET_TYPE_SV_LIST_TEAMS] =
    (cl_sv_packet_destroyer_t)sv_list_teams_packet_destroy,
    [PACKET_TYPE_CL_LIST_CHANNELS] =
    (cl_sv_packet_destroyer_t)cl_list_channels_packet_destroy,
    [PACKET_TYPE_SV_LIST_CHANNELS] =
    (cl_sv_packet_destroyer_t)sv_list_channels_packet_destroy,
    [PACKET_TYPE_CL_LIST_THREADS] =
    (cl_sv_packet_destroyer_t)cl_list_threads_packet_destroy,
    [PACKET_TYPE_SV_LIST_THREADS] =
    (cl_sv_packet_destroyer_t)sv_list_threads_packet_destroy,
    [PACKET_TYPE_CL_LIST_REPLIES] =
    (cl_sv_packet_destroyer_t)cl_list_replies_packet_destroy,
    [PACKET_TYPE_SV_LIST_REPLIES] =
    (cl_sv_packet_destroyer_t)sv_list_replies_packet_destroy,

    [PACKET_TYPE_CL_GET_CURRENT_USER_INFO] =
    (cl_sv_packet_destroyer_t)cl_get_current_user_info_packet_destroy,
    [PACKET_TYPE_SV_GET_CURRENT_USER_INFO] =
    (cl_sv_packet_destroyer_t)sv_get_current_user_info_packet_destroy,
    [PACKET_TYPE_CL_GET_TEAM_INFO] =
    (cl_sv_packet_destroyer_t)cl_get_team_info_packet_destroy,
    [PACKET_TYPE_SV_GET_TEAM_INFO] =
    (cl_sv_packet_destroyer_t)sv_get_team_info_packet_destroy,
    [PACKET_TYPE_CL_GET_CHANNEL_INFO] =
    (cl_sv_packet_destroyer_t)cl_get_channel_info_packet_destroy,
    [PACKET_TYPE_SV_GET_CHANNEL_INFO] =
    (cl_sv_packet_destroyer_t)sv_get_channel_info_packet_destroy,
    [PACKET_TYPE_CL_GET_THREAD_INFO] =
    (cl_sv_packet_destroyer_t)cl_get_thread_info_packet_destroy,
    [PACKET_TYPE_SV_GET_THREAD_INFO] =
    (cl_sv_packet_destroyer_t)sv_get_thread_info_packet_destroy,

    [PACKET_TYPE_SV_ERROR_UNKNOWN_TEAM] =
    (cl_sv_packet_destroyer_t)sv_error_unknown_team_packet_destroy,
    [PACKET_TYPE_SV_ERROR_UNKNOWN_CHANNEL] =
    (cl_sv_packet_destroyer_t)sv_error_unknown_channel_packet_destroy,
    [PACKET_TYPE_SV_ERROR_UNKNOWN_THREAD] =
    (cl_sv_packet_destroyer_t)sv_error_unknown_thread_packet_destroy,
    [PACKET_TYPE_SV_ERROR_UNKNOWN_USER] =
    (cl_sv_packet_destroyer_t)sv_error_unknown_user_packet_destroy,
    [PACKET_TYPE_SV_ERROR_UNAUTHORIZED] =
    (cl_sv_packet_destroyer_t)sv_error_unauthorized_packet_destroy,
    [PACKET_TYPE_SV_ERROR_ALREADY_EXIST] =
    (cl_sv_packet_destroyer_t)sv_error_already_exist_packet_destroy,

    [PACKET_TYPE_SV_DISCONNECTION_SUCCESS] =
    (cl_sv_packet_destroyer_t)sv_disconnection_success_packet_destroy,
};

void cl_sv_packet_destroy(cl_sv_packet_t *self)
{
    packet_type_t type = *(packet_type_t *)self;

    if (type >= PACKET_TYPE_COUNT || handlers[type] == nullptr) {
        printf("[codec] Cannot destroy packet of type %d\n", type);
        return;
    }
    handlers[type](self);
}
