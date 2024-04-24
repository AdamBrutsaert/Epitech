/*
** EPITECH PROJECT, 2024
** data_connect.c
** File description:
** data_connect.c
*/

#include "ftp/data.h"

bool data_connect(data_t *self)
{
    socket_t socket;

    if (self->type != DATA_ACTIVE)
        return false;
    if (!socket_init_tcp(&socket))
        return false;
    if (!socket_connect_ipv4(&socket, &self->address))
        return false;
    tcp_stream_init_from_socket(&self->stream, &socket);
    self->connected = true;
    return true;
}
