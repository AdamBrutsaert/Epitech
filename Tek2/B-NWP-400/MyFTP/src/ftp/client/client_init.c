/*
** EPITECH PROJECT, 2024
** client_init.c
** File description:
** client_init.c
*/

#include "ftp/client.h"

bool client_init(
    client_t *self,
    tcp_stream_t *stream,
    const ipv4_address_t *address,
    const path_t *path
)
{
    control_init(&self->control, stream, address);
    if (!control_send(&self->control, "220 MyFTP\r\n")) {
        control_deinit(&self->control);
        return false;
    }
    if (!path_init_copy(&self->path, path)) {
        control_deinit(&self->control);
        return false;
    }
    data_init(&self->data);
    user_init(&self->user);
    self->state = CLIENT_HANDLING_COMMAND;
    self->pid = -1;
    self->command_args = NULL;
    self->error = false;
    self->quit = false;
    control_log_info(&self->control, "Connected");
    return true;
}
