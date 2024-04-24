/*
** EPITECH PROJECT, 2024
** client_data.c
** File description:
** client_data.c
*/

#include "ftp/client.h"

data_t *client_data(client_t *self)
{
    return &self->data;
}
