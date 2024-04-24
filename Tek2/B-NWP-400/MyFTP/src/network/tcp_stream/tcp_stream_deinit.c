/*
** EPITECH PROJECT, 2024
** tcp_stream_deinit.c
** File description:
** tcp_stream_deinit.c
*/

#include "network/tcp_stream.h"

void tcp_stream_deinit(tcp_stream_t *self)
{
    socket_deinit(self);
}
