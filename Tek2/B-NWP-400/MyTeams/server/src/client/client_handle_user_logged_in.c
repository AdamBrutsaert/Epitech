/*
** EPITECH PROJECT, 2024
** client_handle_user_logged_in.c
** File description:
** client_handle_user_logged_in.c
*/

#include "client.h"

#include "myteams/logging_server.h"

static void logout_if_logged_in(client_t *self)
{
    if (self->user == nullptr)
        return;
    state_broadcast_users_logout(self->state, self->user);
    state_remove_connection(self->state, self->stream);
    server_event_user_logged_out(STRING_CDATA(self->user->uuid));
    self->user = nullptr;
}

static void get_or_create_user(
    client_t *self,
    cl_user_logged_in_packet_t *packet
)
{
    self->user = state_get_user_by_name(self->state, packet->name);
    if (self->user == nullptr) {
        self->user = user_create(packet->name);
        state_add_user(self->state, self->user);
        server_event_user_created(
            STRING_CDATA(self->user->uuid),
            STRING_CDATA(self->user->name)
        );
    }
}

void client_handle_user_logged_in(
    client_t *self,
    cl_user_logged_in_packet_t *packet
)
{
    logout_if_logged_in(self);
    get_or_create_user(self, packet);
    state_add_connection(self->state, self->stream, self->user);
    server_event_user_logged_in(STRING_CDATA(self->user->uuid));
    state_broadcast_users_login(self->state, self->user);
}
