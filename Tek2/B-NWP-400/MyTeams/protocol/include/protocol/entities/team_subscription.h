/*
** EPITECH PROJECT, 2024
** team_subscription.h
** File description:
** team_subscription.h
*/

#pragma once

#include "my/network/packet.h"

typedef struct {
    string_t *team_uuid;
    string_t *user_uuid;
} team_subscription_t;

/******************************* Init & Deinit *******************************/

/// Creates a team subscription
team_subscription_t *team_subscription_create(
    const string_t *team_uuid,
    const string_t *user_uuid
);

/// Destroys a team subscription
void team_subscription_destroy(team_subscription_t *self);

/*****************************************************************************/

/********************************** Methods **********************************/

/// Pushes a team subscription into a packet
void packet_push_team_subscription(
    packet_t *self,
    const team_subscription_t *team
);

/// Pops a team subscription from a packet
bool packet_pop_team_subscription(packet_t *self, team_subscription_t **team);

/// Serializes a team subscription
string_t *team_subscription_serialize(const team_subscription_t *self);

/// Deserializes a team subscription
team_subscription_t *team_subscription_deserialize(const string_t *data);

/*****************************************************************************/
