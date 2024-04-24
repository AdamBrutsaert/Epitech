/*
** EPITECH PROJECT, 2024
** tcp_stream_init_from_socket.c
** File description:
** tcp_stream_init_from_socket.c
*/

#include "network/tcp_stream.h"

void tcp_stream_init_from_socket(tcp_stream_t *self, socket_t *socket)
{
    *self = *socket;
}
