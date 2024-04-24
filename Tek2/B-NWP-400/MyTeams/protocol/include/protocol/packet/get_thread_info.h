/*
** EPITECH PROJECT, 2024
** get_thread_info.h
** File description:
** get_thread_info.h
*/

#pragma once

#include "my/network/packet.h"
#include "protocol/packet/type.h"
#include "protocol/entities/thread.h"

/*********************************** Types ***********************************/

/// Represents a cl_get_thread_info packet
typedef struct {
    packet_type_t type;
    string_t *team_uuid;
    string_t *channel_uuid;
    string_t *thread_uuid;
} cl_get_thread_info_packet_t;

/// Represents a sv_get_thread_info packet
typedef struct {
    packet_type_t type;
    thread_t *thread;
} sv_get_thread_info_packet_t;

/*****************************************************************************/

/*********************************** Client **********************************/

/// Encodes a cl_get_thread_info packet
void cl_get_thread_info_packet_encode(
    cl_get_thread_info_packet_t *self,
    packet_t *packet
);

/// Decodes a cl_get_thread_info packet
bool cl_get_thread_info_packet_decode(
    cl_get_thread_info_packet_t *self,
    packet_t *packet
);

/// Destroys a cl_get_thread_info packet
void cl_get_thread_info_packet_destroy(
    cl_get_thread_info_packet_t *self
);

/*****************************************************************************/

/*********************************** Server **********************************/

/// Encodes a sv_get_thread_info packet
void sv_get_thread_info_packet_encode(
    sv_get_thread_info_packet_t *self,
    packet_t *packet
);

/// Decodes a sv_get_thread_info packet
bool sv_get_thread_info_packet_decode(
    sv_get_thread_info_packet_t *self,
    packet_t *packet
);

/// Destroys a sv_get_thread_info packet
void sv_get_thread_info_packet_destroy(
    sv_get_thread_info_packet_t *self
);

/*****************************************************************************/
