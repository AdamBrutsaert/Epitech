/*
** EPITECH PROJECT, 2024
** type.h
** File description:
** type.h
*/

#pragma once

#include <stdint.h>

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512

/*********************************** Types ***********************************/

/// Represents the type of a packet
typedef enum : uint8_t {
    PACKET_TYPE_INVALID = 255,

    /// Sent by a client to log in
    PACKET_TYPE_CL_USER_LOGGED_IN = 0,
    /// Broadcasted by the server when a user logs in
    PACKET_TYPE_SV_USER_LOGGED_IN,

    /// Sent by a client to log out
    PACKET_TYPE_CL_USER_LOGGED_OUT,
    /// Broadcasted by the server when a user logs out
    PACKET_TYPE_SV_USER_LOGGED_OUT,
    /// Sent to a client to notify his disconnection succeeded
    PACKET_TYPE_SV_DISCONNECTION_SUCCESS,

    /// Sent by a client to get all users
    PACKET_TYPE_CL_GET_ALL_USERS,
    /// List of all users sent by the server
    PACKET_TYPE_SV_GET_ALL_USERS,

    /// Sent by a client to get details about a user
    PACKET_TYPE_CL_GET_USER,
    /// Details about a user sent by the server
    PACKET_TYPE_SV_GET_USER,

    /// Sent by a client to send a private message to a specific user
    PACKET_TYPE_CL_SEND_PRIVATE_MESSAGE,
    /// Sent by the server to acknowledge a private message packet
    PACKET_TYPE_SV_SEND_PRIVATE_MESSAGE,

    /// Sent by a client to get all private messages with a specific user
    PACKET_TYPE_CL_GET_ALL_PRIVATE_MESSAGES,
    /// List of all private messages sent by the server
    PACKET_TYPE_SV_GET_ALL_PRIVATE_MESSAGES,

    /// Sent by a client to subscribe to a team
    PACKET_TYPE_CL_SUBSCRIBE_TO_TEAM,
    /// Broadcasted by the server when a user subscribes to a team
    PACKET_TYPE_SV_SUBSCRIBE_TO_TEAM,

    /// Sent by a client to unsubscribe from a team
    PACKET_TYPE_CL_UNSUBSCRIBE_FROM_TEAM,
    /// Broadcasted by the server when a user unsubscribes from a team
    PACKET_TYPE_SV_UNSUBSCRIBE_FROM_TEAM,

    /// Sent by a client to get all teams in which the user is subscribed
    PACKET_TYPE_CL_LIST_SUBSCRIBED_TEAMS,
    /// List of all teams in which the user is subscribed sent by the server
    PACKET_TYPE_SV_LIST_SUBSCRIBED_TEAMS,

    /// Sent by a client to get all users subscribed to a team
    PACKET_TYPE_CL_LIST_USERS_SUBSCRIBED_TO_TEAM,
    /// List of all users subscribed to a team sent by the server
    PACKET_TYPE_SV_LIST_USERS_SUBSCRIBED_TO_TEAM,

    /// Sent by a client to create a team
    PACKET_TYPE_CL_CREATE_TEAM,
    /// Broadcasted by the server when a team is created
    PACKET_TYPE_SV_CREATE_TEAM,
    /// Sent by the server to confirm the creation of a team
    PACKET_TYPE_SV_CREATED_TEAM_SUCCESSFULLY,

    /// Sent by a client to create a channel in a team
    PACKET_TYPE_CL_CREATE_CHANNEL,
    /// Broadcasted by the server to the team members when a channel is created
    PACKET_TYPE_SV_CREATE_CHANNEL,
    /// Sent by the server to confirm the creation of a channel
    PACKET_TYPE_SV_CREATED_CHANNEL_SUCCESSFULLY,

    /// Sent by a client to create a thread in a channel
    PACKET_TYPE_CL_CREATE_THREAD,
    /// Broadcasted by the server to the team members when a thread is created
    PACKET_TYPE_SV_CREATE_THREAD,
    /// Sent by the server to confirm the creation of a thread
    PACKET_TYPE_SV_CREATED_THREAD_SUCCESSFULLY,

    /// Sent by a client to create a comment in a thread
    PACKET_TYPE_CL_CREATE_REPLY,
    /// Broadcasted by the server to the team members when a comment is created
    PACKET_TYPE_SV_CREATE_REPLY,
    /// Sent by the server to confirm the creation of a comment
    PACKET_TYPE_SV_CREATED_REPLY_SUCCESSFULLY,

    /// Sent by a client to get all teams
    PACKET_TYPE_CL_LIST_TEAMS,
    /// List of all teams sent by the server
    PACKET_TYPE_SV_LIST_TEAMS,

    /// Sent by a client to get all channels in a team
    PACKET_TYPE_CL_LIST_CHANNELS,
    /// List of all channels within a team sent by the server
    PACKET_TYPE_SV_LIST_CHANNELS,

    /// Sent by a client to get all threads in a channel
    PACKET_TYPE_CL_LIST_THREADS,
    /// List of all threads within a channel sent by the server
    PACKET_TYPE_SV_LIST_THREADS,

    /// Sent by a client to get all comments in a thread
    PACKET_TYPE_CL_LIST_REPLIES,
    /// List of all comments within a thread sent by the server
    PACKET_TYPE_SV_LIST_REPLIES,

    /// Sent by a client to get his own info
    PACKET_TYPE_CL_GET_CURRENT_USER_INFO,
    /// Sent by the server to give the user his own info
    PACKET_TYPE_SV_GET_CURRENT_USER_INFO,

    /// Sent by a client to get the info of a team he is subscribed to
    PACKET_TYPE_CL_GET_TEAM_INFO,
    /// Sent by the server to give the user the info of a team
    /// he is subscribed to
    PACKET_TYPE_SV_GET_TEAM_INFO,

    /// Sent by a client to get the info of a channel from a team
    /// he is subscribed to
    PACKET_TYPE_CL_GET_CHANNEL_INFO,
    /// Sent by the server to give the user the info of a channel from a team
    /// he is subscribed to
    PACKET_TYPE_SV_GET_CHANNEL_INFO,

    /// Sent by a client to get the info of a thread from a channel
    /// he is subscribed to
    PACKET_TYPE_CL_GET_THREAD_INFO,
    /// Sent by the server to give the user the info of a thread from a channel
    /// he is subscribed to
    PACKET_TYPE_SV_GET_THREAD_INFO,

    /// Sent by the server when the user try to do an action
    /// with a team that does not exist (list channels, subscribe, etc...)
    /// Can be sent when (un)subscribe, subscribed, list, create, info
    PACKET_TYPE_SV_ERROR_UNKNOWN_TEAM,

    /// Sent by the server when the user try to do an action
    /// with a channel that does not exist (list threads, create thread, etc)
    /// Can be sent when list, create and info are invoked
    PACKET_TYPE_SV_ERROR_UNKNOWN_CHANNEL,

    /// Sent by the server when the user try to do an action
    /// with a thread that does not exist (list replies, create reply, etc...)
    /// Can be sent when list, create and info are invoked
    PACKET_TYPE_SV_ERROR_UNKNOWN_THREAD,

    /// Sent by the server when the user try to do an action
    /// with a user that does not exist (send private message, /user)
    /// Can be sent when send, user, messages are invoked
    PACKET_TYPE_SV_ERROR_UNKNOWN_USER,

    /// Sent by the server when the user try to do an action
    /// when he is not logged in
    /// Can be sent with all commands, except login
    PACKET_TYPE_SV_ERROR_UNAUTHORIZED,

    /// Sent when the user try to do an action and the ressource already exists
    /// Can be sent when create is invoked
    PACKET_TYPE_SV_ERROR_ALREADY_EXIST,

    /// Number of packet types
    PACKET_TYPE_COUNT
} packet_type_t;

/*****************************************************************************/
