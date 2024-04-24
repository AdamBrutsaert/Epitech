/*
** EPITECH PROJECT, 2024
** error_unauthorized.h
** File description:
** error_unauthorized.h
*/

#pragma once

#include "my/network/packet.h"
#include "protocol/packet/type.h"

/*********************************** Types ***********************************/

/// Represents a sv_error_unauthorized packet
typedef struct {
    packet_type_t type;
} sv_error_unauthorized_packet_t;

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_error_unauthorized packet
void sv_error_unauthorized_packet_encode(
    sv_error_unauthorized_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_error_unauthorized packet
bool sv_error_unauthorized_packet_decode(
    sv_error_unauthorized_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_error_unauthorized packet
void sv_error_unauthorized_packet_destroy(
    sv_error_unauthorized_packet_t *self
);

/*****************************************************************************/
