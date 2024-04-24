/*
** EPITECH PROJECT, 2024
** get_all_private_messages.h
** File description:
** get_all_private_messages.h
*/

#pragma once

#include "my/memory/vec.h"
#include "my/network/packet.h"
#include "protocol/packet/type.h"

/*********************************** Types ***********************************/

/// Represents a cl_get_all_private_messages packet
typedef struct {
    packet_type_t type;
    string_t *uuid;
} cl_get_all_private_messages_packet_t;

/// Represents a sv_get_all_private_messages packet
typedef struct {
    packet_type_t type;
    vec_t *messages;
} sv_get_all_private_messages_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_get_all_private_messages packet
void cl_get_all_private_messages_packet_encode(
    cl_get_all_private_messages_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_get_all_private_messages packet
bool cl_get_all_private_messages_packet_decode(
    cl_get_all_private_messages_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_get_all_private_messages packet
void cl_get_all_private_messages_packet_destroy(
    cl_get_all_private_messages_packet_t *self
);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_get_all_private_messages packet
void sv_get_all_private_messages_packet_encode(
    sv_get_all_private_messages_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_get_all_private_messages packet
bool sv_get_all_private_messages_packet_decode(
    sv_get_all_private_messages_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_get_all_private_messages packet
void sv_get_all_private_messages_packet_destroy(
    sv_get_all_private_messages_packet_t *self
);

/*****************************************************************************/
