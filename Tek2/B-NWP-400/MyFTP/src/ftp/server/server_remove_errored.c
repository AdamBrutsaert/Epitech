/*
** EPITECH PROJECT, 2024
** server_remove_errored.c
** File description:
** server_remove_errored.c
*/

#include "ftp/server.h"

void server_remove_errored(server_t *self)
{
    for (size_t i = vec_length(&self->clients); i > 0; i--) {
        if (!client_error(vec_get(&self->clients, i - 1)))
            continue;
        client_deinit(vec_get(&self->clients, i - 1));
        vec_swap(&self->clients, i - 1, vec_length(&self->clients) - 1);
        vec_pop_back(&self->clients);
    }
}
