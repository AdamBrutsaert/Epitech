/*
** EPITECH PROJECT, 2024
** data_register.c
** File description:
** data_register.c
*/

#include "ftp/data.h"

bool data_register(data_t *self, socket_selector_t *selector)
{
    if (self->type != DATA_PASSIVE)
        return true;
    return socket_selector_add_read(selector, &self->listener);
}
