/*
** EPITECH PROJECT, 2024
** server_update.c
** File description:
** server_update.c
*/

#include "ftp/server.h"

void server_update(server_t *self)
{
    for (size_t i = 0; i < vec_length(&self->clients); i++)
        client_update(vec_get(&self->clients, i), &self->selector);
}
