/*
** EPITECH PROJECT, 2024
** control_need_write.c
** File description:
** control_need_write.c
*/

#include "ftp/control.h"

bool control_need_write(const control_t *self)
{
    return !!vec_length(&self->write_buffer);
}
