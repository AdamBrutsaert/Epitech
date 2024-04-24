/*
** EPITECH PROJECT, 2024
** codec.h
** File description:
** codec.h
*/

#pragma once

#include "protocol/packet/user_logged_in.h"
#include "protocol/packet/user_logged_out.h"
#include "protocol/packet/disconnection_success.h"
#include "protocol/packet/send_private_message.h"
#include "protocol/packet/get_all_private_messages.h"
#include "protocol/packet/get_user.h"
#include "protocol/packet/get_all_users.h"

#include "protocol/packet/subscribe_to_team.h"
#include "protocol/packet/unsubscribe_from_team.h"
#include "protocol/packet/list_subscribed_teams.h"
#include "protocol/packet/list_users_subscribed_to_team.h"

#include "protocol/packet/create_team.h"
#include "protocol/packet/create_channel.h"
#include "protocol/packet/create_thread.h"
#include "protocol/packet/create_reply.h"

#include "protocol/packet/list_teams.h"
#include "protocol/packet/list_channels.h"
#include "protocol/packet/list_threads.h"
#include "protocol/packet/list_replies.h"

#include "protocol/packet/get_current_user_info.h"
#include "protocol/packet/get_team_info.h"
#include "protocol/packet/get_channel_info.h"
#include "protocol/packet/get_thread_info.h"

#include "protocol/packet/error_unknown_team.h"
#include "protocol/packet/error_unknown_channel.h"
#include "protocol/packet/error_unknown_thread.h"
#include "protocol/packet/error_unknown_user.h"
#include "protocol/packet/error_unauthorized.h"
#include "protocol/packet/error_already_exist.h"


/*********************************** Types ***********************************/

/// A struct representing any client or server packets
typedef union {
    cl_user_logged_in_packet_t cl_user_logged_in;
    sv_user_logged_in_packet_t sv_user_logged_in;
    cl_user_logged_out_packet_t cl_user_logged_out;
    sv_user_logged_out_packet_t sv_user_logged_out;
    cl_send_private_message_packet_t cl_send_private_message;
    sv_send_private_message_packet_t sv_send_private_message;
    cl_get_all_private_messages_packet_t cl_get_all_private_messages;
    sv_get_all_private_messages_packet_t sv_get_all_private_messages;
    cl_get_user_packet_t cl_get_user;
    sv_get_user_packet_t sv_get_user;
    cl_get_all_users_packet_t cl_get_all_users;
    sv_get_all_users_packet_t sv_get_all_users;

    cl_subscribe_to_team_packet_t cl_subscribe_to_team;
    sv_subscribe_to_team_packet_t sv_subscribe_to_team;
    cl_unsubscribe_from_team_packet_t cl_unsubscribe_from_team;
    sv_unsubscribe_from_team_packet_t sv_unsubscribe_from_team;
    cl_list_subscribed_teams_packet_t cl_list_subscribed_teams;
    sv_list_subscribed_teams_packet_t sv_list_subscribed_teams;
    cl_list_users_subscribed_to_team_packet_t cl_list_users_subscribed_to_team;
    sv_list_users_subscribed_to_team_packet_t sv_list_users_subscribed_to_team;

    cl_create_team_packet_t cl_create_team;
    sv_create_team_packet_t sv_create_team;
    sv_created_team_successfully_packet_t sv_created_team_successfully;
    cl_create_channel_packet_t cl_create_channel;
    sv_create_channel_packet_t sv_create_channel;
    sv_created_channel_successfully_packet_t sv_created_channel_successfully;
    cl_create_thread_packet_t cl_create_thread;
    sv_create_thread_packet_t sv_create_thread;
    sv_created_thread_successfully_packet_t sv_created_thread_successfully;
    cl_create_reply_packet_t cl_create_reply;
    sv_create_reply_packet_t sv_create_reply;
    sv_created_reply_successfully_packet_t sv_created_reply_successfully;

    cl_list_teams_packet_t cl_list_teams;
    sv_list_teams_packet_t sv_list_teams;
    cl_list_channels_packet_t cl_list_channels;
    sv_list_channels_packet_t sv_list_channels;
    cl_list_threads_packet_t cl_list_threads;
    sv_list_threads_packet_t sv_list_threads;
    cl_list_replies_packet_t cl_list_replies;
    sv_list_replies_packet_t sv_list_replies;

    cl_get_current_user_info_packet_t cl_get_current_user_info;
    sv_get_current_user_info_packet_t sv_get_current_user_info;
    cl_get_team_info_packet_t cl_get_team_info;
    sv_get_team_info_packet_t sv_get_team_info;
    cl_get_channel_info_packet_t cl_get_channel_info;
    sv_get_channel_info_packet_t sv_get_channel_info;
    cl_get_thread_info_packet_t cl_get_thread_info;
    sv_get_thread_info_packet_t sv_get_thread_info;

    sv_error_unknown_team_packet_t sv_error_unknown_team;
    sv_error_unknown_channel_packet_t sv_error_unknown_channel;
    sv_error_unknown_thread_packet_t sv_error_unknown_thread;
    sv_error_unknown_user_packet_t sv_error_unknown_user;
    sv_error_unauthorized_packet_t sv_error_unauthorized;
    sv_error_already_exist_packet_t sv_error_already_exist;

    sv_disconnection_success_packet_t sv_disconnection_success;
} cl_sv_packet_t;

/// Represents a function that encodes a client or server packet
typedef void (*cl_sv_packet_encoder_t)(cl_sv_packet_t *, packet_t *);

/// Represents a function that decodes a client or server packet
typedef bool (*cl_sv_packet_decoder_t)(cl_sv_packet_t *, packet_t *);

/// Represents a function that destroys a client or server packet
typedef void (*cl_sv_packet_destroyer_t)(cl_sv_packet_t *);

/// Forwards declaration of user
struct user;

/// Forwards declaration of message
struct message;

/*****************************************************************************/

/*********************************** CL/SV ***********************************/

/// Pushes a client or server packet into a packet
void packet_push_cl_sv_packet(packet_t *self, cl_sv_packet_t *packet);

/// Pops a client or server packet from a packet
bool packet_pop_cl_sv_packet(packet_t *self, cl_sv_packet_t **packet);

/// Destroys a client or server packet
void cl_sv_packet_destroy(cl_sv_packet_t *self);

/*****************************************************************************/
