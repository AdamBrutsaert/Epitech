/*
** EPITECH PROJECT, 2024
** list_users_subscribed_to_team.h
** File description:
** list_users_subscribed_to_team.h
*/

#pragma once

#include "my/network/packet.h"
#include "protocol/packet/type.h"

/*********************************** Types ***********************************/

/// Represents a cl_list_users_subscribed_to_team packet
typedef struct {
    packet_type_t type;
    string_t *uuid;
} cl_list_users_subscribed_to_team_packet_t;

/// Represents a sv_list_users_subscribed_to_team packet
typedef struct {
    packet_type_t type;
    vec_t *users;
} sv_list_users_subscribed_to_team_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_list_users_subscribed_to_team packet
void cl_list_users_subscribed_to_team_packet_encode(
    cl_list_users_subscribed_to_team_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_list_users_subscribed_to_team packet
bool cl_list_users_subscribed_to_team_packet_decode(
    cl_list_users_subscribed_to_team_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_list_users_subscribed_to_team packet
void cl_list_users_subscribed_to_team_packet_destroy(
    cl_list_users_subscribed_to_team_packet_t *self
);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_list_users_subscribed_to_team packet
void sv_list_users_subscribed_to_team_packet_encode(
    sv_list_users_subscribed_to_team_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_list_users_subscribed_to_team packet
bool sv_list_users_subscribed_to_team_packet_decode(
    sv_list_users_subscribed_to_team_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_list_users_subscribed_to_team packet
void sv_list_users_subscribed_to_team_packet_destroy(
    sv_list_users_subscribed_to_team_packet_t *self
);

/*****************************************************************************/
