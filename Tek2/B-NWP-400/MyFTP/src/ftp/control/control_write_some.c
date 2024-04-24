/*
** EPITECH PROJECT, 2024
** control_write_some.c
** File description:
** control_write_some.c
*/

#include "ftp/control.h"

bool control_write_some(control_t *self)
{
    ssize_t bytes = tcp_stream_write(
        &self->stream,
        vec_data(&self->write_buffer),
        vec_length(&self->write_buffer)
    );

    if (bytes <= 0)
        return false;
    control_log_info(self, "Wrote %zi bytes", bytes);
    vec_pop_some_front(&self->write_buffer, bytes);
    return true;
}
