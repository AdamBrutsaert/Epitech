/*
** EPITECH PROJECT, 2024
** thread.h
** File description:
** thread.h
*/

#pragma once

#include "my/memory/string.h"
#include "my/network/packet.h"

#include <time.h>

/*********************************** Types ***********************************/

/// Represents a thread
typedef struct {
    string_t *uuid;
    string_t *channel_uuid;
    string_t *user_uuid;
    time_t timestamp;
    string_t *title;
    string_t *body;
} thread_t;

/// Represents args required to create a thread
typedef struct {
    string_t *channel_uuid;
    string_t *user_uuid;
    time_t timestamp;
    string_t *title;
    string_t *body;
} thread_create_args_t;

/*****************************************************************************/


/******************************* Init & Deinit *******************************/

/// Creates an thread
thread_t *thread_create(const thread_create_args_t *args);

/// Loads an thread
thread_t *thread_load(const string_t *uuid, const thread_create_args_t *args);

/// Destroys an thread
void thread_destroy(thread_t *self);

/*****************************************************************************/

/********************************** Methods **********************************/

/// Pushes an thread into a packet
void packet_push_thread(packet_t *self, const thread_t *thread);

/// Pops an thread from a packet
bool packet_pop_thread(packet_t *self, thread_t **thread);

/// Pushes a vector of threads into a packet
void packet_push_thread_vec(packet_t *self, const vec_t *threads);

/// Pops a vector of threads from a packet
bool packet_pop_thread_vec(packet_t *self, vec_t **threads);

/// Serializes an thread
string_t *thread_serialize(const thread_t *self);

/// Deserializes an thread
thread_t *thread_deserialize(const string_t *data);

/*****************************************************************************/
