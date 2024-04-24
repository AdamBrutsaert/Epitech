/*
** EPITECH PROJECT, 2024
** client_destroy.c
** File description:
** client_destroy.c
*/

#include "client.h"

#include "my/memory/allocation.h"
#include "myteams/logging_server.h"

void client_destroy(client_t *self)
{
    if (self->user != nullptr) {
        state_remove_connection(self->state, self->stream);
        state_broadcast_users_logout(self->state, self->user);
        server_event_user_logged_out(STRING_CDATA(self->user->uuid));
    }
    stream_destroy(self->stream);
    deallocate(self);
}
