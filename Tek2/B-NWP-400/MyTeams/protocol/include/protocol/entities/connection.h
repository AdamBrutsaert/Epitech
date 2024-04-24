/*
** EPITECH PROJECT, 2024
** connection.h
** File description:
** connection.h
*/

#pragma once

#include "protocol/stream.h"
#include "user.h"

/*********************************** Types ***********************************/

/// Represents a connection
typedef struct {
    stream_t *stream;
    user_t *user;
} connection_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a connection
connection_t *connection_create(stream_t *stream, user_t *user);

/// Destroys a connection
void connection_destroy(connection_t *self);

/*****************************************************************************/
