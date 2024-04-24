/*
** EPITECH PROJECT, 2024
** control_send.c
** File description:
** control_send.c
*/

#include "ftp/control.h"

#include <string.h>

bool control_send(control_t *self, const char *message)
{
    return vec_push_some(&self->write_buffer, message, strlen(message));
}
