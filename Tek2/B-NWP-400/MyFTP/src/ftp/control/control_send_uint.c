/*
** EPITECH PROJECT, 2024
** control_send_uint.c
** File description:
** control_send_uint.c
*/

#include "ftp/control.h"

bool control_send_uint(control_t *self, uintmax_t value)
{
    if (value >= 10 && !control_send_uint(self, value / 10))
        return false;
    return vec_push(&self->write_buffer, &"0123456789"[value % 10]);
}
