/*
** EPITECH PROJECT, 2024
** client.h
** File description:
** client.h
*/

#pragma once

#include "state.h"

#include "protocol/stream.h"

/*********************************** Types ***********************************/

/// Represents a client
typedef struct {
    stream_t *stream;
    state_t *state;
    user_t *user;
} client_t;

/// Represents a packet handler
typedef struct {
    bool require_login;
    void (*handler)(client_t *, cl_sv_packet_t *);
} packet_handler_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a client
client_t *client_create(socket_t *socket, state_t *state);

/// Deinitializes a client
void client_destroy(client_t *self);

/*****************************************************************************/

/********************************* Handlers **********************************/

/// Dispatches packets to the appropriate handler
void client_handle_packets(client_t *self);

/// Handles the user logged in packet
void client_handle_user_logged_in(
    client_t *self,
    cl_user_logged_in_packet_t *packet
);

/// Handles the user logged out packet
void client_handle_user_logged_out(
    client_t *self,
    cl_user_logged_out_packet_t *packet
);

/// Handles the send private message packet
void client_handle_send_private_message(
    client_t *self,
    cl_send_private_message_packet_t *packet
);

/// Handles the get all private messages packet
void client_handle_get_all_private_messages(
    client_t *self,
    cl_get_all_private_messages_packet_t *packet
);

/// Handles the get user packet
void client_handle_get_user(
    client_t *self,
    cl_get_user_packet_t *packet
);

/// Handles the get all users packet
void client_handle_get_all_users(
    client_t *self,
    cl_get_all_users_packet_t *packet
);

/// Handles the subscribe to team packet
void client_handle_subscribe_to_team(
    client_t *self,
    cl_subscribe_to_team_packet_t *packet
);

/// Handles the unsubscribe from team packet
void client_handle_unsubscribe_from_team(
    client_t *self,
    cl_unsubscribe_from_team_packet_t *packet
);

/// Handles the list subscribed teams packet
void client_handle_list_subscribed_teams(
    client_t *self,
    cl_list_subscribed_teams_packet_t *packet
);

/// Handles the list users subscribed to team packet
void client_handle_list_users_subscribed_to_team(
    client_t *self,
    cl_list_users_subscribed_to_team_packet_t *packet
);

/// Handles the create team packet
void client_handle_create_team(
    client_t *self,
    cl_create_team_packet_t *packet
);

/// Handles the create channel packet
void client_handle_create_channel(
    client_t *self,
    cl_create_channel_packet_t *packet
);

/// Handles the create thread packet
void client_handle_create_thread(
    client_t *self,
    cl_create_thread_packet_t *packet
);

/// Handles the create reply packet
void client_handle_create_reply(
    client_t *self,
    cl_create_reply_packet_t *packet
);

/// Handles the list teams packet
void client_handle_list_teams(
    client_t *self,
    cl_list_teams_packet_t *packet
);

/// Handles the list channels packet
void client_handle_list_channels(
    client_t *self,
    cl_list_channels_packet_t *packet
);

/// Handles the list threads packet
void client_handle_list_threads(
    client_t *self,
    cl_list_threads_packet_t *packet
);

/// Handles the list replies packet
void client_handle_list_replies(
    client_t *self,
    cl_list_replies_packet_t *packet
);

/// Handles the get current user info packet
void client_handle_get_current_user_info(
    client_t *self,
    cl_get_current_user_info_packet_t *packet
);

/// Handles the get team info packet
void client_handle_get_team_info(
    client_t *self,
    cl_get_team_info_packet_t *packet
);

/// Handles the get channel info packet
void client_handle_get_channel_info(
    client_t *self,
    cl_get_channel_info_packet_t *packet
);

/// Handles the get thread info packet
void client_handle_get_thread_info(
    client_t *self,
    cl_get_thread_info_packet_t *packet
);

/*****************************************************************************/
