/*
** EPITECH PROJECT, 2024
** error_unknown_user.h
** File description:
** error_unknown_user.h
*/

#pragma once

#include "my/network/packet.h"
#include "protocol/packet/type.h"

/*********************************** Types ***********************************/

/// Represents a sv_error_unknown_user packet
typedef struct {
    packet_type_t type;
    string_t *uuid;
} sv_error_unknown_user_packet_t;

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_error_unknown_user packet
void sv_error_unknown_user_packet_encode(
    sv_error_unknown_user_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_error_unknown_user packet
bool sv_error_unknown_user_packet_decode(
    sv_error_unknown_user_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_error_unknown_user packet
void sv_error_unknown_user_packet_destroy(
    sv_error_unknown_user_packet_t *self
);

/*****************************************************************************/
