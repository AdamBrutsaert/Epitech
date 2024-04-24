/*
** EPITECH PROJECT, 2024
** get_all_users.h
** File description:
** get_all_users.h
*/

#pragma once

#include "my/memory/vec.h"
#include "my/network/packet.h"
#include "protocol/packet/type.h"

/*********************************** Types ***********************************/

/// Represents a cl_get_all_users packet
typedef struct {
    packet_type_t type;
} cl_get_all_users_packet_t;

/// Represents a sv_get_all_users packet
typedef struct {
    packet_type_t type;
    vec_t *users;
} sv_get_all_users_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_get_all_users packet
void cl_get_all_users_packet_encode(
    cl_get_all_users_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_get_all_users packet
bool cl_get_all_users_packet_decode(
    cl_get_all_users_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_get_all_users packet
void cl_get_all_users_packet_destroy(cl_get_all_users_packet_t *self);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_get_all_users packet
void sv_get_all_users_packet_encode(
    sv_get_all_users_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_get_all_users packet
bool sv_get_all_users_packet_decode(
    sv_get_all_users_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_get_all_users packet
void sv_get_all_users_packet_destroy(sv_get_all_users_packet_t *self);

/*****************************************************************************/
