/*
** EPITECH PROJECT, 2024
** reply.h
** File description:
** reply.h
*/

#pragma once

#include "my/memory/string.h"
#include "my/network/packet.h"

#include <time.h>

/*********************************** Types ***********************************/

/// Represents a reply
typedef struct {
    string_t *thread_uuid;
    string_t *user_uuid;
    time_t timestamp;
    string_t *body;
} reply_t;

/*****************************************************************************/


/******************************* Init & Deinit *******************************/

/// Creates an reply
reply_t *reply_create(
    const string_t *thread_uuid,
    const string_t *user_uuid,
    time_t timestamp,
    const string_t *body
);

/// Destroys an reply
void reply_destroy(reply_t *self);

/*****************************************************************************/

/********************************** Methods **********************************/

/// Pushes an reply into a packet
void packet_push_reply(packet_t *self, const reply_t *reply);

/// Pops an reply from a packet
bool packet_pop_reply(packet_t *self, reply_t **reply);

/// Pushes a vector of replys into a packet
void packet_push_reply_vec(packet_t *self, const vec_t *replys);

/// Pops a vector of replys from a packet
bool packet_pop_reply_vec(packet_t *self, vec_t **replys);

/// Serializes an reply
string_t *reply_serialize(const reply_t *self);

/// Deserializes an reply
reply_t *reply_deserialize(const string_t *data);

/*****************************************************************************/
