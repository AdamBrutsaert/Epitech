/*
** EPITECH PROJECT, 2024
** client_set_state.c
** File description:
** client_set_state.c
*/

#include "ftp/client.h"

void client_set_state(client_t *self, client_state_t state)
{
    self->state = state;
}
