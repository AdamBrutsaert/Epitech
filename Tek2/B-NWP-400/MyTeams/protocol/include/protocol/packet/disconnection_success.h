/*
** EPITECH PROJECT, 2024
** disconnection_success.h
** File description:
** disconnection_success.h
*/

#pragma once

#include "my/network/packet.h"
#include "protocol/packet/type.h"

/*********************************** Types ***********************************/

/// Represents a sv_disconnection_success packet
typedef struct {
    packet_type_t type;
} sv_disconnection_success_packet_t;

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_disconnection_success packet
void sv_disconnection_success_packet_encode(
    sv_disconnection_success_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_disconnection_success packet
bool sv_disconnection_success_packet_decode(
    sv_disconnection_success_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_disconnection_success packet
void sv_disconnection_success_packet_destroy(
    sv_disconnection_success_packet_t *self
);

/*****************************************************************************/
