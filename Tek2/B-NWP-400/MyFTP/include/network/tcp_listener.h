/*
** EPITECH PROJECT, 2024
** tcp_listener.h
** File description:
** tcp_listener.h
*/

#pragma once

#include "tcp_stream.h"

/****************************** Data structures ******************************/

/// Represents a TCP listener
typedef socket_t tcp_listener_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Initializes a TCP listener
bool tcp_listener_init(tcp_listener_t *self, const ipv4_address_t *address);

/// Deinitializes a TCP listener
void tcp_listener_deinit(tcp_listener_t *self);

/*****************************************************************************/

/********************************** Accept ***********************************/

/// Accepts an incoming connection on a TCP listener
bool tcp_listener_accept(
    tcp_listener_t *self,
    tcp_stream_t *peer,
    ipv4_address_t *address
);

/*****************************************************************************/
