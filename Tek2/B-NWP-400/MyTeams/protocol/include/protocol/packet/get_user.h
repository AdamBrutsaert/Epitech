/*
** EPITECH PROJECT, 2024
** get_user.h
** File description:
** get_user.h
*/

#pragma once

#include "my/memory/string.h"
#include "my/network/packet.h"
#include "protocol/packet/type.h"
#include "protocol/entities/user.h"

/*********************************** Types ***********************************/

/// Represents a cl_get_user packet
typedef struct {
    packet_type_t type;
    string_t *uuid;
} cl_get_user_packet_t;

/// Represents a sv_get_user packet
typedef struct {
    packet_type_t type;
    user_t *user;
} sv_get_user_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_get_user packet
void cl_get_user_packet_encode(
    cl_get_user_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_get_user packet
bool cl_get_user_packet_decode(
    cl_get_user_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_get_user packet
void cl_get_user_packet_destroy(cl_get_user_packet_t *self);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_get_user packet
void sv_get_user_packet_encode(
    sv_get_user_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_get_user packet
bool sv_get_user_packet_decode(
    sv_get_user_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_get_user packet
void sv_get_user_packet_destroy(sv_get_user_packet_t *self);

/*****************************************************************************/
