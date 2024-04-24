/*
** EPITECH PROJECT, 2024
** data_disconnect.c
** File description:
** data_disconnect.c
*/

#include "ftp/data.h"

void data_disconnect(data_t *self)
{
    if (self->type == DATA_NONE)
        return;
    if (self->type == DATA_PASSIVE)
        tcp_listener_deinit(&self->listener);
    if (self->connected)
        tcp_stream_deinit(&self->stream);
    self->type = DATA_NONE;
    self->connected = false;
}
