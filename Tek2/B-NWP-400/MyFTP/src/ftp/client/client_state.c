/*
** EPITECH PROJECT, 2024
** client_state.c
** File description:
** client_state.c
*/

#include "ftp/client.h"

client_state_t client_state(const client_t *self)
{
    return self->state;
}
