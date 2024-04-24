/*
** EPITECH PROJECT, 2024
** control_deinit.c
** File description:
** control_deinit.c
*/

#include "ftp/control.h"

void control_deinit(control_t *self)
{
    control_log_info(self, "Disconnected");
    tcp_stream_deinit(&self->stream);
    vec_deinit(&self->read_buffer);
    vec_deinit(&self->write_buffer);
}
