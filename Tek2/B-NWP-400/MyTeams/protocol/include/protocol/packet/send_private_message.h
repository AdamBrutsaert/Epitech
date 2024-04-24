/*
** EPITECH PROJECT, 2024
** send_private_message.h
** File description:
** send_private_message.h
*/

#pragma once

#include "protocol/packet/type.h"

#include "my/memory/string.h"
#include "my/network/packet.h"

/*********************************** Types ***********************************/

/// Represents a send_private_message packet
typedef struct {
    packet_type_t type;
    string_t *message;
    string_t *to_uuid;
} cl_send_private_message_packet_t;

typedef struct {
    packet_type_t type;
    string_t *message;
    string_t *from_uuid;
} sv_send_private_message_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_send_private_message packet
void cl_send_private_message_packet_encode(
    cl_send_private_message_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_send_private_message packet
bool cl_send_private_message_packet_decode(
    cl_send_private_message_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_send_private_message packet
void cl_send_private_message_packet_destroy(
    cl_send_private_message_packet_t *self
);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_send_private_message packet
void sv_send_private_message_packet_encode(
    sv_send_private_message_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_send_private_message packet
bool sv_send_private_message_packet_decode(
    sv_send_private_message_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_send_private_message packet
void sv_send_private_message_packet_destroy(
    sv_send_private_message_packet_t *self
);

/*****************************************************************************/
