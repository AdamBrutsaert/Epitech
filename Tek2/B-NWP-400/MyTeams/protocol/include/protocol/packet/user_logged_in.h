/*
** EPITECH PROJECT, 2024
** user_logged_in.h
** File description:
** user_logged_in.h
*/

#pragma once

#include "protocol/packet/type.h"
#include "my/memory/string.h"
#include "my/network/packet.h"

/*********************************** Types ***********************************/

/// Represents a cl_user_logged_in packet
typedef struct {
    packet_type_t type;
    string_t *name;
} cl_user_logged_in_packet_t;

/// Represents a sv_user_logged_in packet
typedef struct {
    packet_type_t type;
    string_t *name;
    string_t *uuid;
} sv_user_logged_in_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_user_logged_in packet
void cl_user_logged_in_packet_encode(
    cl_user_logged_in_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_user_logged_in packet
bool cl_user_logged_in_packet_decode(
    cl_user_logged_in_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_user_logged_in packet
void cl_user_logged_in_packet_destroy(cl_user_logged_in_packet_t *self);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_user_logged_in packet
void sv_user_logged_in_packet_encode(
    sv_user_logged_in_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_user_logged_in packet
bool sv_user_logged_in_packet_decode(
    sv_user_logged_in_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_user_logged_in packet
void sv_user_logged_in_packet_destroy(sv_user_logged_in_packet_t *self);

/*****************************************************************************/
