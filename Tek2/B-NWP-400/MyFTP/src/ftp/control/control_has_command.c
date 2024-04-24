/*
** EPITECH PROJECT, 2024
** control_has_command.c
** File description:
** control_has_command.c
*/

#include "ftp/control.h"

bool control_has_command(const control_t *self)
{
    const char *data = vec_data((vec_t *)&self->read_buffer);

    for (size_t i = 0; i + 1 < vec_length(&self->read_buffer); i++) {
        if (data[i] == '\r' && data[i + 1] == '\n')
            return true;
    }
    return false;
}
