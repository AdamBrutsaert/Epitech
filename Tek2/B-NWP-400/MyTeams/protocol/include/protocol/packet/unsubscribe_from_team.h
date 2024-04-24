/*
** EPITECH PROJECT, 2024
** unsubscribe_from_team.h
** File description:
** unsubscribe_from_team.h
*/

#pragma once

#include "my/memory/string.h"
#include "my/network/packet.h"
#include "protocol/packet/type.h"
#include "protocol/entities/team_subscription.h"

/*********************************** Types ***********************************/

/// Represents a cl_unsubscribe_from_team packet
typedef struct {
    packet_type_t type;
    string_t *uuid;
} cl_unsubscribe_from_team_packet_t;

/// Represents a sv_unsubscribe_from_team packet
typedef struct {
    packet_type_t type;
    team_subscription_t *team_subscription;
} sv_unsubscribe_from_team_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_unsubscribe_from_team packet
void cl_unsubscribe_from_team_packet_encode(
    cl_unsubscribe_from_team_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_unsubscribe_from_team packet
bool cl_unsubscribe_from_team_packet_decode(
    cl_unsubscribe_from_team_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_unsubscribe_from_team packet
void cl_unsubscribe_from_team_packet_destroy(
    cl_unsubscribe_from_team_packet_t *self
);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_unsubscribe_from_team packet
void sv_unsubscribe_from_team_packet_encode(
    sv_unsubscribe_from_team_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_unsubscribe_from_team packet
bool sv_unsubscribe_from_team_packet_decode(
    sv_unsubscribe_from_team_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_unsubscribe_from_team packet
void sv_unsubscribe_from_team_packet_destroy(
    sv_unsubscribe_from_team_packet_t *self
);

/*****************************************************************************/
