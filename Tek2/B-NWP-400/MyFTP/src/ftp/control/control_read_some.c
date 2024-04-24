/*
** EPITECH PROJECT, 2024
** control_read_some.c
** File description:
** control_read_some.c
*/

#include "ftp/control.h"

bool control_read_some(control_t *self)
{
    char buffer[1024];
    ssize_t bytes;

    bytes = tcp_stream_read(&self->stream, buffer, 1024);
    if (bytes <= 0)
        return false;
    control_log_info(self, "Read %zi bytes", bytes);
    if (vec_length(&self->read_buffer) >= 1024)
        vec_clear(&self->read_buffer);
    return vec_push_some(&self->read_buffer, buffer, bytes);
}
