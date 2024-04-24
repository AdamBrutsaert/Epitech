/*
** EPITECH PROJECT, 2024
** server_register.c
** File description:
** server_register.c
*/

#include "ftp/server.h"

bool server_register(server_t *self)
{
    for (size_t i = 0; i < vec_length(&self->clients); i++)
        client_register(vec_get(&self->clients, i), &self->selector);
    return socket_selector_add_read(&self->selector, &self->listener);
}
