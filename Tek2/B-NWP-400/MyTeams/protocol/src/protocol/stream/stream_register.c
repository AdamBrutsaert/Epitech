/*
** EPITECH PROJECT, 2024
** stream_register.c
** File description:
** stream_register.c
*/

#include "protocol/stream.h"

bool stream_register(stream_t *self, selector_t *selector)
{
    return selector_add_read(selector, self->socket)
        && (VEC_LEN(self->write_buffer) == 0
            || selector_add_write(selector, self->socket));
}
