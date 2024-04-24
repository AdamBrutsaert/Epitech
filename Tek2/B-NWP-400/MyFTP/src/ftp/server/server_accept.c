/*
** EPITECH PROJECT, 2024
** server_accept.c
** File description:
** server_accept.c
*/

#include "ftp/server.h"

bool server_accept(server_t *self)
{
    tcp_stream_t peer;
    ipv4_address_t address;
    client_t client;

    if (!tcp_listener_accept(&self->listener, &peer, &address))
        return false;
    if (!SOCKET_SELECTOR_CAN_REGISTER(peer)) {
        tcp_stream_deinit(&peer);
        return true;
    }
    if (!client_init(&client, &peer, &address, &self->path)) {
        tcp_stream_deinit(&peer);
        return true;
    }
    if (!vec_push(&self->clients, &client)) {
        client_deinit(&client);
        return false;
    }
    return true;
}
