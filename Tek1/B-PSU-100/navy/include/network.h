/*
** EPITECH PROJECT, 2023
** network.h
** File description:
** network.h
*/

#pragma once

#include "buffer.h"

#include <signal.h>

typedef enum {
    CREATE,
    DESTROY,
    LENGTH,
    PUSH,
    POP,
    GET,
    SET,
} network_operation_t;

void network_initialize(void);
void network_terminate(void);

int8_t network_listen(void);
int8_t network_connect(pid_t pid, bit_t status);

int8_t network_send_position(int8_t line, int8_t column);
void network_receive_position(int8_t *line, int8_t *column);

int8_t network_send_status(int8_t status);
int8_t network_receive_status(void);

bit_t network_receive_bit(void);
int8_t network_send_bit(bit_t bit);

int8_t network_receive_byte(void);
int8_t network_send_byte(int8_t byte);

void network_peer(network_operation_t operation, pid_t *pid);
void network_buffer(network_operation_t operation, void *data);
