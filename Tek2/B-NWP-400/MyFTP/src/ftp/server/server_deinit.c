/*
** EPITECH PROJECT, 2024
** server_deinit.c
** File description:
** server_deinit.c
*/

#include "ftp/server.h"
#include "utils/logging.h"

void server_deinit(server_t *self)
{
    for (size_t i = 0; i < vec_length(&self->clients); i++)
        client_deinit(vec_get(&self->clients, i));
    vec_deinit(&self->clients);
    tcp_listener_deinit(&self->listener);
    path_deinit(&self->path);
    log_info("[server] Closed");
}
