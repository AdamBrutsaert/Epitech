/*
** EPITECH PROJECT, 2024
** state.h
** File description:
** state.h
*/

#pragma once

#include "protocol/entities/user.h"
#include "protocol/entities/connection.h"
#include "protocol/entities/message.h"
#include "protocol/entities/team.h"
#include "protocol/entities/team_subscription.h"
#include "protocol/entities/channel.h"
#include "protocol/entities/thread.h"
#include "protocol/entities/reply.h"

/*********************************** Types ***********************************/

/// Represents a state
typedef struct {
    vec_t *users;
    vec_t *connections;
    vec_t *messages;
    vec_t *teams;
    vec_t *team_subscriptions;
    vec_t *channels;
    vec_t *threads;
    vec_t *replies;
} state_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a state
state_t *state_create(void);

/// Destroys a state
void state_destroy(state_t *self);

/*****************************************************************************/

/******************************** Connections ********************************/

/// Adds a connection
void state_add_connection(state_t *self, stream_t *stream, user_t *user);

/// Removes a connection
void state_remove_connection(state_t *self, const stream_t *stream);

/*****************************************************************************/

/*********************************** Users ***********************************/

/// Gets an user by its name
user_t *state_get_user_by_name(state_t *self, const string_t *name);

/// Gets an user by its UUID
user_t *state_get_user_by_uuid(state_t *self, const string_t *uuid);

/// Adds an user
void state_add_user(state_t *self, user_t *user);

/// Sends a packet to an user
void state_send_packet_to_user(
    state_t *self,
    user_t *user,
    cl_sv_packet_t *packet
);

/// Broadcasts users someone login
void state_broadcast_users_login(state_t *self, user_t *user);

/// Broadcasts users someone logout
void state_broadcast_users_logout(state_t *self, user_t *user);

/*****************************************************************************/

/********************************* Messages **********************************/

/// Adds a message
void state_add_message(state_t *self, message_t *message);

/// Gets all messages between two users
vec_t *state_get_messages_between(state_t *self, user_t *user1, user_t *user2);

/*****************************************************************************/

/********************************** Teams ************************************/

/// Adds a team
void state_add_team(state_t *self, team_t *team);

/// Gets a team by its UUID
team_t *state_get_team_by_uuid(state_t *self, const string_t *uuid);

/// Gets a team byt its name
team_t *state_get_team_by_name(state_t *self, const string_t *name);

/// Gets a subscription
team_subscription_t *state_get_subscription(
    state_t *self,
    user_t *user,
    team_t *team
);

/// Adds a subscription
void state_add_subscription(state_t *self, team_subscription_t *subscription);

/// Removes a subscription
void state_remove_subscription(state_t *self, user_t *user, team_t *team);

/// Get all subscriptions of an user
vec_t *state_get_subscribed_teams(state_t *self, user_t *user);

/// Get users subscribed to a team
vec_t *state_get_users_subscribed_to_team(state_t *self, team_t *team);

/// Checks if an user is subscribed to a team
bool state_is_user_subscribed(state_t *self, user_t *user, team_t *team);

/// Broadcasts users a team has been created
void state_broadcast_team_created(state_t *self, team_t *team);

/*****************************************************************************/

/******************************** Channels ***********************************/

/// Adds a channel
void state_add_channel(state_t *self, channel_t *channel);

/// Gets a channel by its UUID
channel_t *state_get_channel_by_uuid(state_t *self, const string_t *uuid);

/// Gets a channel by its name
channel_t *state_get_channel_by_name(
    state_t *self,
    team_t *team,
    const string_t *name
);

/// Get all channels of a team
vec_t *state_get_channels_of_team(state_t *self, team_t *team);

/// Broadcasts subscribed users a channel has been created
void state_broadcast_channel_created(state_t *self, channel_t *channel);

/*****************************************************************************/

/********************************** Threads **********************************/

/// Adds a thread
void state_add_thread(state_t *self, thread_t *thread);

/// Gets a thread by its UUID
thread_t *state_get_thread_by_uuid(state_t *self, const string_t *uuid);

/// Get all threads of a channel
vec_t *state_get_threads_of_channel(state_t *self, channel_t *channel);

/// Broadcasts subscribed users a thread has been created
void state_broadcast_thread_created(state_t *self, thread_t *thread);

/*****************************************************************************/

/********************************** Replies **********************************/

/// Adds a reply
void state_add_reply(state_t *self, reply_t *reply);

/// Broadcasts subscribed users a reply has been created
void state_broadcast_reply_created(state_t *self, reply_t *reply);

/// Get all replies of a thread
vec_t *state_get_replies_of_thread(state_t *self, thread_t *thread);

/*****************************************************************************/

/********************************** Saves ************************************/

/// Saves the state
void state_save(state_t *self);

/// Restores the state
void state_restore(state_t *self);

/// Saves the users
void state_save_users(state_t *self);

/// Restores the users
void state_restore_users(state_t *self);

/// Saves the messages
void state_save_messages(state_t *self);

/// Restores the messages
void state_restore_messages(state_t *self);

/// Saves the teams
void state_save_teams(state_t *self);

/// Restores the teams
void state_restore_teams(state_t *self);

/// Saves the team subscriptions
void state_save_team_subscriptions(state_t *self);

/// Restores the team subscriptions
void state_restore_team_subscriptions(state_t *self);

/// Saves the channels
void state_save_channels(state_t *self);

/// Restores the channels
void state_restore_channels(state_t *self);

/// Saves the threads
void state_save_threads(state_t *self);

/// Restores the threads
void state_restore_threads(state_t *self);

/// Saves the replies
void state_save_replies(state_t *self);

/// Restores the replies
void state_restore_replies(state_t *self);

/*****************************************************************************/
