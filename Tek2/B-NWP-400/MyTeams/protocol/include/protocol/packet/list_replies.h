/*
** EPITECH PROJECT, 2024
** list_replies.h
** File description:
** list_replies.h
*/

#pragma once

#include "my/network/packet.h"
#include "protocol/packet/type.h"

/*********************************** Types ***********************************/

/// Represents a cl_list_replies packet
typedef struct {
    packet_type_t type;
    string_t *team_uuid;
    string_t *channel_uuid;
    string_t *thread_uuid;
} cl_list_replies_packet_t;

/// Represents a sv_list_replies packet
typedef struct {
    packet_type_t type;
    vec_t *replies;
} sv_list_replies_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_list_replies packet
void cl_list_replies_packet_encode(
    cl_list_replies_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_list_replies packet
bool cl_list_replies_packet_decode(
    cl_list_replies_packet_t *self,
    packet_t *packet
);

/// Destroies a cl_list_replies packet
void cl_list_replies_packet_destroy(cl_list_replies_packet_t *self);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_list_replies packet
void sv_list_replies_packet_encode(
    sv_list_replies_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_list_replies packet
bool sv_list_replies_packet_decode(
    sv_list_replies_packet_t *self,
    packet_t *packet
);

/// Destroies a sv_list_replies packet
void sv_list_replies_packet_destroy(sv_list_replies_packet_t *self);

/*****************************************************************************/
