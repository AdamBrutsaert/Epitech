/*
** EPITECH PROJECT, 2024
** cli.h
** File description:
** cli.h
*/

#pragma once

#include "parsing/reader.h"
#include "parsing/parser.h"
#include "protocol/stream.h"
#include "protocol/codec.h"
#include "my/network/selector.h"

/*********************************** Types ***********************************/

/// Represents a cli
typedef struct {
    socket_t *socket;
    stream_t *stream;
    selector_t *selector;
    reader_t *reader;
    bool running;

    // Contexts
    string_t *context_team_uuid;
    string_t *context_channel_uuid;
    string_t *context_thread_uuid;
} cli_t;

/// Represents a command handler
typedef struct {
    const char *cmd;
    void (*handler)(cli_t *, command_t *);
} command_handler_t;

/// Represents a packet handler
typedef void (*packet_handler_t)(cli_t *, cl_sv_packet_t *);

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a cli
cli_t *cli_create(void);

/// Destroys a cli
void cli_destroy(cli_t *self);

/// Destroys context
void cli_context_destroy(cli_t *self);

/*****************************************************************************/

/********************************** Methods **********************************/

int cli_run_from_args(int ac, char **av);

/// Runs the CLI
bool cli_run(cli_t *self, const ipv4_address_t *address);

/// Dispatch received packet
void cli_handle_packets(cli_t *self);

/// Handles input command
void cli_handle_input(cli_t *self);

/*****************************************************************************/

/****************************** Command Handler ******************************/

/// Handles help command - Only client side
void cli_handle_command_help(cli_t *self, command_t *cmd);

/// Handles login command
void cli_handle_command_login(cli_t *self, command_t *cmd);

/// Handles logout command
void cli_handle_command_logout(cli_t *self, command_t *cmd);

/// Handles send private message
void cli_handle_command_send(cli_t *self, command_t *cmd);

/// Handles messages command
void cli_handle_command_messages(cli_t *self, command_t *cmd);

/// Handles get user command
void cli_handle_get_user_command(cli_t *self, command_t *cmd);

/// Handles get all usesr command
void cli_handle_command_get_all_users(cli_t *self, command_t *cmd);

/// Handles subscribe command
void cli_handle_command_subscribe(cli_t *self, command_t *cmd);

/// Handles unsubscribe command
void cli_handle_command_unsubscribe(cli_t *self, command_t *cmd);

/// Handles subscribed command
void cli_handle_command_subscribed(cli_t *self, command_t *cmd);

/// Handles use command
void cli_handle_command_use_context(cli_t *self, command_t *cmd);

/// Handles create command
void cli_handle_command_create(cli_t *self, command_t *cmd);

/// Handles list command
void cli_handle_command_list(cli_t *self, command_t *cmd);

/// Handles info command
void cli_handle_command_info(cli_t *self, command_t *cmd);

/*****************************************************************************/

/****************************** Packet Handler *******************************/

/// Handles sv_user_logged_in packet
void cli_handle_packet_sv_user_logged_in(
    cli_t *self,
    sv_user_logged_in_packet_t *packet
);

/// Handles sv_user_logged_out packet
void cli_handle_packet_sv_user_logged_out(
    cli_t *self,
    sv_user_logged_out_packet_t *packet
);

/// Handles sv_send_private_message packet
void cli_handle_packet_sv_send_private_message(
    cli_t *self,
    sv_send_private_message_packet_t *packet
);

/// Handles sv_get_all_private_messages packet
void cli_handle_packet_sv_get_all_private_messages(
    cli_t *self,
    sv_get_all_private_messages_packet_t *packet
);

/// Handles sv_get_user packet
void cli_handle_packet_sv_get_user(
    cli_t *self,
    sv_get_user_packet_t *packet
);

/// Handles sv_get_all_users packet
void cli_handle_packet_sv_get_all_users(
    cli_t *self,
    sv_get_all_users_packet_t *packet
);

/// Handles sv_subscribe_to_team packet
void cli_handle_packet_sv_subscribe_to_team(
    cli_t *self,
    sv_subscribe_to_team_packet_t *packet
);

/// Handles sv_unsubscribe_from_team packet
void cli_handle_packet_sv_unsubscribe_from_team(
    cli_t *self,
    sv_unsubscribe_from_team_packet_t *packet
);

/// Handles sv_list_subscribed_teams packet
void cli_handle_packet_sv_list_subscribed_teams(
    cli_t *self,
    sv_list_subscribed_teams_packet_t *packet
);

/// Handles sv_list_users_subscribed_to_team packet
void cli_handle_packet_sv_list_users_subscribed_to_team(
    cli_t *self,
    sv_list_users_subscribed_to_team_packet_t *packet
);

/// Handles sv_create_team packet
void cli_handle_packet_sv_create_team(
    cli_t *self,
    sv_create_team_packet_t *packet
);

/// Handles sv_created_team_successfully packet
void cli_handle_packet_sv_created_team_successfully(
    cli_t *self,
    sv_created_team_successfully_packet_t *packet
);

/// Handles sv_create_channel packet
void cli_handle_packet_sv_create_channel(
    cli_t *self,
    sv_create_channel_packet_t *packet
);

/// Handles sv_created_channel_successfully packet
void cli_handle_packet_sv_created_channel_successfully(
    cli_t *self,
    sv_created_channel_successfully_packet_t *packet
);

/// Handles sv_create_thread packet
void cli_handle_packet_sv_create_thread(
    cli_t *self,
    sv_create_thread_packet_t *packet
);

/// Handles sv_created_thread_successfully packet
void cli_handle_packet_sv_created_thread_successfully(
    cli_t *self,
    sv_created_thread_successfully_packet_t *packet
);

/// Handles sv_create_reply packet
void cli_handle_packet_sv_create_reply(
    cli_t *self,
    sv_create_reply_packet_t *packet
);

/// Handles sv_created_reply_successfully packet
void cli_handle_packet_sv_created_reply_successfully(
    cli_t *self,
    sv_created_reply_successfully_packet_t *packet
);

/// Handles sv_list_teams packet
void cli_handle_packet_sv_list_teams(
    cli_t *self,
    sv_list_teams_packet_t *packet
);

/// Handles sv_list_channels packet
void cli_handle_packet_sv_list_channels(
    cli_t *self,
    sv_list_channels_packet_t *packet
);

/// Handles sv_list_threads packet
void cli_handle_packet_sv_list_threads(
    cli_t *self,
    sv_list_threads_packet_t *packet
);

/// Handles sv_list_replies packet
void cli_handle_packet_sv_list_replies(
    cli_t *self,
    sv_list_replies_packet_t *packet
);

/// Handles sv_get_current_user_info packet
void cli_handle_packet_sv_get_current_user_info(
    cli_t *self,
    sv_get_current_user_info_packet_t *packet
);

/// Handles sv_get_team_info packet
void cli_handle_packet_sv_get_team_info(
    cli_t *self,
    sv_get_team_info_packet_t *packet
);

/// Handles sv_get_channel_info packet
void cli_handle_packet_sv_get_channel_info(
    cli_t *self,
    sv_get_channel_info_packet_t *packet
);
/// Handles sv_get_thread_info packet
void cli_handle_packet_sv_get_thread_info(
    cli_t *self,
    sv_get_thread_info_packet_t *packet
);

/// Handles sv_error_unknown_team packet
void cli_handle_packet_sv_error_unknown_team(
    cli_t *self,
    sv_error_unknown_team_packet_t *packet
);

/// Handles sv_error_unknown_channel packet
void cli_handle_packet_sv_error_unknown_channel(
    cli_t *self,
    sv_error_unknown_channel_packet_t *packet
);

/// Handles sv_error_unknown_thread packet
void cli_handle_packet_sv_error_unknown_thread(
    cli_t *self,
    sv_error_unknown_thread_packet_t *packet
);

/// Handles sv_error_unknown_user packet
void cli_handle_packet_sv_error_unknown_user(
    cli_t *self,
    sv_error_unknown_user_packet_t *packet
);

/// Handles sv_error_unauthorized packet
void cli_handle_packet_sv_error_unauthorized(
    cli_t *self,
    sv_error_unauthorized_packet_t *packet
);

/// Handles sv_error_already_exist packet
void cli_handle_packet_sv_error_already_exist(
    cli_t *self,
    sv_error_already_exist_packet_t *packet
);

/// Handles sv_disconnection_sucess packet
void cli_handle_packet_sv_disconnection_success(
    cli_t *self,
    sv_disconnection_success_packet_t *packet
);

/*****************************************************************************/
