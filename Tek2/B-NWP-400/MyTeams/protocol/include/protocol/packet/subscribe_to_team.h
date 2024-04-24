/*
** EPITECH PROJECT, 2024
** subscribe_to_team.h
** File description:
** subscribe_to_team.h
*/

#pragma once

#include "my/memory/string.h"
#include "my/network/packet.h"
#include "protocol/packet/type.h"
#include "protocol/entities/team_subscription.h"

/*********************************** Types ***********************************/

/// Represents a cl_subscribe_to_team packet
typedef struct {
    packet_type_t type;
    string_t *uuid;
} cl_subscribe_to_team_packet_t;

/// Represents a sv_subscribe_to_team packet
typedef struct {
    packet_type_t type;
    team_subscription_t *team_subscription;
} sv_subscribe_to_team_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_subscribe_to_team packet
void cl_subscribe_to_team_packet_encode(
    cl_subscribe_to_team_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_subscribe_to_team packet
bool cl_subscribe_to_team_packet_decode(
    cl_subscribe_to_team_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_subscribe_to_team packet
void cl_subscribe_to_team_packet_destroy(cl_subscribe_to_team_packet_t *self);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_subscribe_to_team packet
void sv_subscribe_to_team_packet_encode(
    sv_subscribe_to_team_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_subscribe_to_team packet
bool sv_subscribe_to_team_packet_decode(
    sv_subscribe_to_team_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_subscribe_to_team packet
void sv_subscribe_to_team_packet_destroy(sv_subscribe_to_team_packet_t *self);

/*****************************************************************************/
