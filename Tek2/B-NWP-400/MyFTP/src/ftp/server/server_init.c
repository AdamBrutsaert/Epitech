/*
** EPITECH PROJECT, 2024
** server_init.c
** File description:
** server_init.c
*/

#include "ftp/server.h"
#include "utils/logging.h"

bool server_init(server_t *self, const ipv4_address_t *address, path_t *path)
{
    if (!tcp_listener_init(&self->listener, address))
        return false;
    self->path = *path;
    socket_selector_init(&self->selector);
    vec_init(&self->clients, sizeof(client_t));
    log_info(
        "[server] Listening on %d.%d.%d.%d:%d ",
        (address->address >> 24) & 0xFF,
        (address->address >> 16) & 0xFF,
        (address->address >> 8) & 0xFF,
        address->address & 0xFF,
        address->port
    );
    return true;
}
