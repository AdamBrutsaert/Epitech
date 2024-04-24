/*
** EPITECH PROJECT, 2024
** data_update.c
** File description:
** data_update.c
*/

#include "ftp/data.h"

static bool accept_peer(data_t *self)
{
    tcp_stream_t stream;
    ipv4_address_t address;

    if (!tcp_listener_accept(&self->listener, &stream, &address))
        return false;
    if (self->connected) {
        tcp_stream_deinit(&self->stream);
        return true;
    }
    self->stream = stream;
    self->connected = true;
    return true;
}

bool data_update(data_t *self, socket_selector_t *selector)
{
    if (self->type != DATA_PASSIVE)
        return true;
    if (socket_selector_can_read(selector, &self->listener))
        return accept_peer(self);
    return true;
}
