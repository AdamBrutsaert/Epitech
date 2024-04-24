/*
** EPITECH PROJECT, 2024
** client_control.c
** File description:
** client_control.c
*/

#include "ftp/client.h"

control_t *client_control(client_t *self)
{
    return &self->control;
}
