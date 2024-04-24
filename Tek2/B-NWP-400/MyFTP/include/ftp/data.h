/*
** EPITECH PROJECT, 2024
** data.h
** File description:
** data.h
*/

#pragma once

#include "network/tcp_listener.h"
#include "network/socket_selector.h"

/****************************** Data structures ******************************/

/// Represents the type of the data
typedef enum {
    DATA_NONE = 0,
    DATA_ACTIVE,
    DATA_PASSIVE,
} data_type_t;

/// Represents the data
typedef struct {
    data_type_t type;
    bool connected;
    ipv4_address_t address;
    tcp_listener_t listener;
    tcp_stream_t stream;
} data_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Initializes the data
void data_init(data_t *self);

/// Deinitializes the data
void data_deinit(data_t *self);

/*****************************************************************************/

/********************************** Update ***********************************/

/// Registers the data to the socket selector
bool data_register(data_t *self, socket_selector_t *selector);

/// Updates the data
bool data_update(data_t *self, socket_selector_t *selector);

/*****************************************************************************/

/******************************** Connection *********************************/

/// Returns the type of the data
data_type_t data_type(data_t *self);

/// Setup active data connection
void data_active(data_t *self, const ipv4_address_t *address);

/// Setup passive data connection
bool data_passive(data_t *self, ipv4_address_t *address);

/// Connects the data for active mode
bool data_connect(data_t *self);

/// Disconnect the data
void data_disconnect(data_t *self);

/// Returns whether the data is connected
bool data_is_connected(data_t *self);

/*****************************************************************************/
