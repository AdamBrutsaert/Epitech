/*
** EPITECH PROJECT, 2024
** create_channel.h
** File description:
** create_channel.h
*/

#pragma once

#include "my/memory/string.h"
#include "my/network/packet.h"
#include "protocol/packet/type.h"
#include "protocol/entities/channel.h"

/*********************************** Types ***********************************/

/// Represents a cl_create_channel packet
typedef struct {
    packet_type_t type;
    string_t *team_uuid;
    string_t *name;
    string_t *description;
} cl_create_channel_packet_t;

/// Represents a sv_create_channel packet
typedef struct {
    packet_type_t type;
    channel_t *channel;
} sv_create_channel_packet_t;

/// Represents a sv_created_channel_successfully packet
typedef struct {
    packet_type_t type;
    channel_t *channel;
} sv_created_channel_successfully_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_create_channel packet
void cl_create_channel_packet_encode(
    cl_create_channel_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_create_channel packet
bool cl_create_channel_packet_decode(
    cl_create_channel_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_create_channel packet
void cl_create_channel_packet_destroy(cl_create_channel_packet_t *self);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_create_channel packet
void sv_create_channel_packet_encode(
    sv_create_channel_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_create_channel packet
bool sv_create_channel_packet_decode(
    sv_create_channel_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_create_channel packet
void sv_create_channel_packet_destroy(sv_create_channel_packet_t *self);

/// Encodes a sv_created_channel_successfully packet
void sv_created_channel_successfully_packet_encode(
    sv_created_channel_successfully_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_created_channel_successfully packet
bool sv_created_channel_successfully_packet_decode(
    sv_created_channel_successfully_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_created_channel_successfully packet
void sv_created_channel_successfully_packet_destroy(
    sv_created_channel_successfully_packet_t *self
);

/*****************************************************************************/
