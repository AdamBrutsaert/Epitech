/*
** EPITECH PROJECT, 2024
** data_is_connected.c
** File description:
** data_is_connected.c
*/

#include "ftp/data.h"

bool data_is_connected(data_t *self)
{
    return self->connected;
}
