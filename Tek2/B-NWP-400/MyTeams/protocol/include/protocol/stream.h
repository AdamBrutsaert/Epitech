/*
** EPITECH PROJECT, 2024
** stream.h
** File description:
** stream.h
*/

#pragma once

#include "my/network/socket.h"
#include "my/network/selector.h"
#include "my/memory/vec.h"

#include "protocol/codec.h"

/*********************************** Types ***********************************/

/// Represents a stream
typedef struct {
    socket_t *socket;
    vec_t *packets;
    vec_t *read_buffer;
    vec_t *write_buffer;
} stream_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates a stream
stream_t *stream_create(socket_t *socket);

/// Destroys a stream
void stream_destroy(stream_t *self);

/*****************************************************************************/

/****************************** Send & Receive *******************************/

/// Checks whether a stream has a packet available
#define STREAM_HAS_PACKET(self) (VEC_LEN((self)->packets) > 0)

/// Sends a packet to a stream
void stream_send_packet(stream_t *self, cl_sv_packet_t *packet);

/// Checks the type of the next packet
packet_type_t stream_peek_packet_type(stream_t *self);

/// Retrieves the next packet from a stream
bool stream_pop_packet(stream_t *self, cl_sv_packet_t **packet);

/// Discards the next packet from a stream
void stream_discard_packet(stream_t *self);

/*****************************************************************************/

/***************************** Register & Update *****************************/

/// Registers a stream to a selector
bool stream_register(stream_t *self, selector_t *selector);

/// Updates a stream
bool stream_update(stream_t *self, selector_t *selector);

/*****************************************************************************/
