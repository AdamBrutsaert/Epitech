/*
** EPITECH PROJECT, 2024
** control.h
** File description:
** control.h
*/

#pragma once

#include "network/tcp_stream.h"
#include "network/socket_selector.h"
#include "memory/vec.h"

/****************************** Data structures ******************************/

/// Represents the control stream of a client
typedef struct {
    tcp_stream_t stream;
    ipv4_address_t address;
    vec_t read_buffer;
    vec_t write_buffer;
} control_t;

/*****************************************************************************/

/******************************* Init & Deinit *******************************/

/// Initializes the control
void control_init(
    control_t *self,
    tcp_stream_t *stream,
    const ipv4_address_t *address
);

/// Deinitializes the control
void control_deinit(control_t *self);

/*****************************************************************************/

/********************************** Update ***********************************/

/// Registers the control to the socket selector
bool control_register(control_t *self, socket_selector_t *selector);

/// Updates the control
bool control_update(control_t *self, socket_selector_t *selector);

/*****************************************************************************/

/******************************** Read/Write *********************************/

/// Reads some data from the control
bool control_read_some(control_t *self);

/// Flushes some data to the control
bool control_write_some(control_t *self);

/// Sends a message to the control
bool control_send(control_t *self, const char *message);

/// Sends an unsigned integer to the control
bool control_send_uint(control_t *self, uintmax_t value);

/// Checks if the control needs to write
bool control_need_write(const control_t *self);

/// Checks if the control has a command available
bool control_has_command(const control_t *self);

/// Retrieves the first available command from the control
char *control_get_command(control_t *self);

/*****************************************************************************/

/********************************** Logging **********************************/

void control_log_info(control_t *self, const char *format, ...);

/*****************************************************************************/
