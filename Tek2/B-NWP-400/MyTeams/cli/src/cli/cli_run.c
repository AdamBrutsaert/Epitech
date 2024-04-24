/*
** EPITECH PROJECT, 2024
** cli_run.c
** File description:
** cli_run.c
*/

#include "cli.h"

#include <unistd.h>
#include <stdio.h>

static bool handle_selector(cli_t *self)
{
    if (!selector_add_read(self->selector, &(socket_t){STDIN_FILENO}))
        return false;
    if (!stream_register(self->stream, self->selector))
        return false;
    if (!selector_wait(self->selector, 0))
        return false;
    return true;
}

static void handle_data(cli_t *self)
{
    cli_handle_packets(self);
    if (reader_contains_newline(self->reader))
        cli_handle_input(self);
}

static bool connect_to_serve(cli_t *self, const ipv4_address_t *address)
{
    if (!socket_open_ipv4_tcp(self->socket))
        return false;
    if (!socket_connect_ipv4(self->socket, address)) {
        printf("[cli] Failed to connect to the server\n");
        return false;
    }
    self->stream = stream_create(self->socket);
    self->socket = nullptr;
    return true;
}

bool cli_run(cli_t *self, const ipv4_address_t *address)
{
    if (!connect_to_serve(self, address))
        return false;
    while (self->running) {
        if (!handle_selector(self))
            return false;
        if (!stream_update(self->stream, self->selector)) {
            printf("[cli] Disconnected from server\n");
            return true;
        }
        if (selector_can_read(self->selector, &(socket_t){STDIN_FILENO})
            && !reader_push_stdin(self->reader))
            return true;
        handle_data(self);
    }
    return true;
}
