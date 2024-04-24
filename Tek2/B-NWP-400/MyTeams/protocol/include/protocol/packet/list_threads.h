/*
** EPITECH PROJECT, 2024
** list_threads.h
** File description:
** list_threads.h
*/

#pragma once

#include "my/network/packet.h"
#include "protocol/packet/type.h"

/*********************************** Types ***********************************/

/// Represents a cl_list_threads packet
typedef struct {
    packet_type_t type;
    string_t *team_uuid;
    string_t *channel_uuid;
} cl_list_threads_packet_t;

/// Represents a sv_list_threads packet
typedef struct {
    packet_type_t type;
    vec_t *threads;
} sv_list_threads_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_list_threads packet
void cl_list_threads_packet_encode(
    cl_list_threads_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_list_threads packet
bool cl_list_threads_packet_decode(
    cl_list_threads_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_list_threads packet
void cl_list_threads_packet_destroy(cl_list_threads_packet_t *self);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_list_threads packet
void sv_list_threads_packet_encode(
    sv_list_threads_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_list_threads packet
bool sv_list_threads_packet_decode(
    sv_list_threads_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_list_threads packet
void sv_list_threads_packet_destroy(sv_list_threads_packet_t *self);

/*****************************************************************************/
