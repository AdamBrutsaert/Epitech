/*
** EPITECH PROJECT, 2024
** control_register.c
** File description:
** control_register.c
*/

#include "ftp/control.h"

bool control_register(control_t *self, socket_selector_t *selector)
{
    if (vec_length(&self->write_buffer) == 0)
        return socket_selector_add_read(selector, &self->stream);
    return socket_selector_add_write(selector, &self->stream);
}
