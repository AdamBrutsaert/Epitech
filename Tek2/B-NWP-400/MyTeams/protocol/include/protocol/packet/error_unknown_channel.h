/*
** EPITECH PROJECT, 2024
** error_unknown_channel.h
** File description:
** error_unknown_channel.h
*/

#pragma once

#include "my/network/packet.h"
#include "protocol/packet/type.h"

/*********************************** Types ***********************************/

/// Represents a sv_error_unknown_channel packet
typedef struct {
    packet_type_t type;
    string_t *uuid;
} sv_error_unknown_channel_packet_t;

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_error_unknown_channel packet
void sv_error_unknown_channel_packet_encode(
    sv_error_unknown_channel_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_error_unknown_channel packet
bool sv_error_unknown_channel_packet_decode(
    sv_error_unknown_channel_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_error_unknown_channel packet
void sv_error_unknown_channel_packet_destroy(
    sv_error_unknown_channel_packet_t *self
);

/*****************************************************************************/
