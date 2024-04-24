/*
** EPITECH PROJECT, 2024
** client_error.c
** File description:
** client_error.c
*/

#include "ftp/client.h"

bool client_error(const client_t *self)
{
    return self->error;
}
