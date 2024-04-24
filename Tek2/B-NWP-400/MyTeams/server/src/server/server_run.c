/*
** EPITECH PROJECT, 2024
** server_run.c
** File description:
** server_run.c
*/

#include "server.h"
#include "client.h"

#include <signal.h>
#include <stdio.h>

static bool is_server_running(bool modify, bool new_value)
{
    static volatile bool is_server_running = true;

    if (modify)
        is_server_running = new_value;
    return is_server_running;
}

static void on_sigint(__attribute__((unused)) int code)
{
    is_server_running(true, false);
}

static void setup_signal_handler(void)
{
    struct sigaction action;

    action.sa_flags = 0;
    action.sa_handler = on_sigint;
    sigemptyset(&action.sa_mask);
    sigaction(SIGINT, &action, NULL);
}

static void remove_signal_handler(void)
{
    struct sigaction action;

    action.sa_flags = 0;
    action.sa_handler = SIG_DFL;
    sigemptyset(&action.sa_mask);
    sigaction(SIGINT, &action, NULL);
}

static bool server_accept_client(server_t *self)
{
    socket_t *peer;
    ipv4_address_t address;
    client_t *client;

    if (!socket_accept_ipv4(self->socket, &peer, &address))
        return false;
    if (!SELECTOR_CAN_REGISTER(peer)) {
        socket_destroy(peer);
        return false;
    }
    client = client_create(peer, self->state);
    vec_push_back(self->clients, &client);
    return true;
}

static void server_remove_client(server_t *self, size_t index)
{
    client_destroy(*(client_t **)VEC_AT(self->clients, index));
    vec_swap(self->clients, index, VEC_LEN(self->clients) - 1);
    vec_pop_back(self->clients);
}

static bool server_register(server_t *self)
{
    client_t *client;

    if (!selector_add_read(self->selector, self->socket))
        return false;
    for (size_t i = VEC_LEN(self->clients); i > 0; i--) {
        client = *(client_t **)VEC_AT(self->clients, i - 1);
        if (!stream_register(client->stream, self->selector))
            server_remove_client(self, i - 1);
    }
    return true;
}

static bool server_update(server_t *self)
{
    client_t *client;

    if (selector_can_read(self->selector, self->socket)
        && !server_accept_client(self))
        return false;
    for (size_t i = VEC_LEN(self->clients); i > 0; i--) {
        client = *(client_t **)VEC_AT(self->clients, i - 1);
        if (!stream_update(client->stream, self->selector)) {
            server_remove_client(self, i - 1);
            continue;
        }
        if (STREAM_HAS_PACKET(client->stream))
            client_handle_packets(client);
    }
    return true;
}

static bool setup_listening(server_t *self, const ipv4_address_t *address)
{
    if (!socket_open_ipv4_tcp(self->socket))
        return false;
    if (!socket_bind_ipv4(self->socket, address))
        return false;
    if (!socket_listen(self->socket, 10))
        return false;
    return true;
}

bool server_run(server_t *self, const ipv4_address_t *address)
{
    if (!setup_listening(self, address))
        return false;
    setup_signal_handler();
    while (is_server_running(false, false)) {
        if (!server_register(self))
            return false;
        if (!selector_wait(self->selector, 0))
            break;
        if (!server_update(self))
            return false;
    }
    remove_signal_handler();
    return true;
}
