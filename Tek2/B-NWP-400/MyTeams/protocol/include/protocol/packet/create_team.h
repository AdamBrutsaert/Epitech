/*
** EPITECH PROJECT, 2024
** create_team.h
** File description:
** create_team.h
*/

#pragma once

#include "my/memory/string.h"
#include "my/network/packet.h"
#include "protocol/packet/type.h"
#include "protocol/entities/team.h"

/*********************************** Types ***********************************/

/// Represents a cl_create_team packet
typedef struct {
    packet_type_t type;
    string_t *name;
    string_t *description;
} cl_create_team_packet_t;

/// Represents a sv_create_team packet
typedef struct {
    packet_type_t type;
    team_t *team;
} sv_create_team_packet_t;

/// Represents a sv_created_team_successfully packet
typedef struct {
    packet_type_t type;
    team_t *team;
} sv_created_team_successfully_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_create_team packet
void cl_create_team_packet_encode(
    cl_create_team_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_create_team packet
bool cl_create_team_packet_decode(
    cl_create_team_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_create_team packet
void cl_create_team_packet_destroy(cl_create_team_packet_t *self);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_create_team packet
void sv_create_team_packet_encode(
    sv_create_team_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_create_team packet
bool sv_create_team_packet_decode(
    sv_create_team_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_create_team packet
void sv_create_team_packet_destroy(sv_create_team_packet_t *self);

/// Encodes a sv_created_team_successfully packet
void sv_created_team_successfully_packet_encode(
    sv_created_team_successfully_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_created_team_successfully packet
bool sv_created_team_successfully_packet_decode(
    sv_created_team_successfully_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_created_team_successfully packet
void sv_created_team_successfully_packet_destroy(
    sv_created_team_successfully_packet_t *self
);

/*****************************************************************************/
