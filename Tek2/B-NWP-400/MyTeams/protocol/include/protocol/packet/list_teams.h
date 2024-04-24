/*
** EPITECH PROJECT, 2024
** list_teams.h
** File description:
** list_teams.h
*/

#pragma once

#include "my/network/packet.h"
#include "protocol/packet/type.h"

/*********************************** Types ***********************************/

/// Represents a cl_list_teams packet
typedef struct {
    packet_type_t type;
} cl_list_teams_packet_t;

/// Represents a sv_list_teams packet
typedef struct {
    packet_type_t type;
    vec_t *teams;
} sv_list_teams_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_list_teams packet
void cl_list_teams_packet_encode(
    cl_list_teams_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_list_teams packet
bool cl_list_teams_packet_decode(
    cl_list_teams_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_list_teams packet
void cl_list_teams_packet_destroy(cl_list_teams_packet_t *self);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_list_teams packet
void sv_list_teams_packet_encode(
    sv_list_teams_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_list_teams packet
bool sv_list_teams_packet_decode(
    sv_list_teams_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_list_teams packet
void sv_list_teams_packet_destroy(sv_list_teams_packet_t *self);

/*****************************************************************************/
