/*
** EPITECH PROJECT, 2024
** tcp_listener_deinit.c
** File description:
** tcp_listener_deinit.c
*/

#include "network/tcp_listener.h"

void tcp_listener_deinit(tcp_listener_t *self)
{
    socket_deinit(self);
}
