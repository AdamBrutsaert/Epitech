/*
** EPITECH PROJECT, 2024
** teams.h
** File description:
** teams.h
*/

#pragma once

#include "my/memory/string.h"
#include "my/network/packet.h"

/*********************************** Types ***********************************/

/// Represents a team
typedef struct {
    string_t *uuid;
    string_t *name;
    string_t *description;
} team_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Creates an team
team_t *team_create(const string_t *name, const string_t *description);

/// Loads an team
team_t *team_load(
    const string_t *uuid,
    const string_t *name,
    const string_t *description
);

/// Destroys an team
void team_destroy(team_t *self);

/*****************************************************************************/

/********************************** Methods **********************************/

/// Pushes an team into a packet
void packet_push_team(packet_t *self, const team_t *team);

/// Pops an team from a packet
bool packet_pop_team(packet_t *self, team_t **team);

/// Pushes a vector of teams into a packet
void packet_push_team_vec(packet_t *self, const vec_t *teams);

/// Pops a vector of teams from a packet
bool packet_pop_team_vec(packet_t *self, vec_t **teams);

/// Serializes an team
string_t *team_serialize(const team_t *self);

/// Deserializes an team
team_t *team_deserialize(const string_t *data);

/*****************************************************************************/
