/*
** EPITECH PROJECT, 2024
** users.h
** File description:
** users.h
*/

#pragma once

#include "my/memory/string.h"
#include "my/network/packet.h"

/*********************************** Types ***********************************/

/// Represents an user
typedef struct {
    string_t *uuid;
    string_t *name;
    size_t connections;
} user_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates an user
user_t *user_create(const string_t *name);

/// Loads an user
user_t *user_load(const string_t *uuid, const string_t *name);

/// Destroys an user
void user_destroy(user_t *self);

/*****************************************************************************/

/********************************** Methods **********************************/

/// Pushes an user into a packet
void packet_push_user(packet_t *self, const user_t *user);

/// Pops an user from a packet
bool packet_pop_user(packet_t *self, user_t **user);

/// Pushes a vector of users into a packet
void packet_push_user_vec(packet_t *self, const vec_t *users);

/// Pops a vector of users from a packet
bool packet_pop_user_vec(packet_t *self, vec_t **users);

/// Serializes an user
string_t *user_serialize(const user_t *self);

/// Deserializes an user
user_t *user_deserialize(const string_t *data);

/*****************************************************************************/
