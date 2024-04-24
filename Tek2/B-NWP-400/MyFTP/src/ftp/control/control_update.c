/*
** EPITECH PROJECT, 2024
** control_update.c
** File description:
** control_update.c
*/

#include "ftp/control.h"

bool control_update(control_t *self, socket_selector_t *selector)
{
    if (socket_selector_can_read(selector, &self->stream))
        return control_read_some(self);
    if (socket_selector_can_write(selector, &self->stream))
        return control_write_some(self);
    return true;
}
