/*
** EPITECH PROJECT, 2024
** data_passive.c
** File description:
** data_passive.c
*/

#include "ftp/data.h"

bool data_passive(data_t *self, ipv4_address_t *address)
{
    data_disconnect(self);
    if (!tcp_listener_init(&self->listener, &(ipv4_address_t){ 0, 0 }))
        return false;
    self->type = DATA_PASSIVE;
    self->connected = false;
    if (!socket_get_local_address_ipv4(&self->listener, address)) {
        data_disconnect(self);
        return false;
    }
    return true;
}
