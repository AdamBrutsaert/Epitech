/*
** EPITECH PROJECT, 2024
** client_register.c
** File description:
** client_register.c
*/

#include "ftp/client.h"

void client_register(client_t *self, socket_selector_t *selector)
{
    if (self->error)
        return;
    if (!control_register(&self->control, selector))
        self->error = true;
    if (!data_register(&self->data, selector))
        self->error = true;
}
