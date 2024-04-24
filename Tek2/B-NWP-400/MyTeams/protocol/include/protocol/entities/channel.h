/*
** EPITECH PROJECT, 2024
** channel.h
** File description:
** channel.h
*/

#pragma once

#include "my/memory/string.h"
#include "my/network/packet.h"

/*********************************** Types ***********************************/

/// Represents a channel
typedef struct {
    string_t *uuid;
    string_t *team_uuid;
    string_t *name;
    string_t *description;
} channel_t;

/*****************************************************************************/


/******************************* Init & Deinit *******************************/

/// Creates an channel
channel_t *channel_create(
    const string_t *team_uuid,
    const string_t *name,
    const string_t *description
);

/// Loads an channel
channel_t *channel_load(
    const string_t *uuid,
    const string_t *team_uuid,
    const string_t *name,
    const string_t *description
);

/// Destroys an channel
void channel_destroy(channel_t *self);

/*****************************************************************************/

/********************************** Methods **********************************/

/// Pushes an channel into a packet
void packet_push_channel(packet_t *self, const channel_t *channel);

/// Pops an channel from a packet
bool packet_pop_channel(packet_t *self, channel_t **channel);

/// Pushes a vector of channels into a packet
void packet_push_channel_vec(packet_t *self, const vec_t *channels);

/// Pops a vector of channels from a packet
bool packet_pop_channel_vec(packet_t *self, vec_t **channels);

/// Serializes an channel
string_t *channel_serialize(const channel_t *self);

/// Deserializes an channel
channel_t *channel_deserialize(const string_t *data);

/*****************************************************************************/
