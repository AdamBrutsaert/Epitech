/*
** EPITECH PROJECT, 2024
** control_init.c
** File description:
** control_init.c
*/

#include "ftp/control.h"

void control_init(
    control_t *self,
    tcp_stream_t *stream,
    const ipv4_address_t *address
)
{
    self->stream = *stream;
    self->address = *address;
    vec_init(&self->read_buffer, sizeof(char));
    vec_init(&self->write_buffer, sizeof(char));
}
