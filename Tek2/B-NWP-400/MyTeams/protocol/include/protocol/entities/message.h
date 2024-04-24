/*
** EPITECH PROJECT, 2024
** messages.h
** File description:
** messages.h
*/

#pragma once

#include "my/memory/string.h"
#include "my/network/packet.h"

#include <time.h>

/*********************************** Types ***********************************/

/// Represents an message
typedef struct message {
    string_t *from_uuid;
    string_t *to_uuid;
    string_t *message;
    time_t timestamp;
} message_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a message
message_t *message_create(
    const string_t *from_uuid,
    const string_t *to_uuid,
    const string_t *message,
    const time_t timestamp
);

/// Destroys a message
void message_destroy(message_t *self);

/*****************************************************************************/

/********************************** Methods **********************************/

/// Pushes a message into a packet
void packet_push_message(packet_t *self, const message_t *message);

/// Pops a message from a packet
bool packet_pop_message(packet_t *self, message_t **message);

/// Pushes a vector of message into a packet
void packet_push_message_vec(packet_t *self, const vec_t *messages);

/// Pops a vector of message from a packet
bool packet_pop_message_vec(packet_t *self, vec_t **messages);

/// Serializes a message
string_t *message_serialize(const message_t *self);

/// Deserializes a message
message_t *message_deserialize(const string_t *data);

/*****************************************************************************/
