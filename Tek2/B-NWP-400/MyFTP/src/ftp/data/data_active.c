/*
** EPITECH PROJECT, 2024
** data_active.c
** File description:
** data_active.c
*/

#include "ftp/data.h"

void data_active(data_t *self, const ipv4_address_t *address)
{
    data_disconnect(self);
    self->type = DATA_ACTIVE;
    self->connected = false;
    self->address = *address;
}
