/*
** EPITECH PROJECT, 2024
** data_init.c
** File description:
** data_init.c
*/

#include "ftp/data.h"

void data_init(data_t *self)
{
    self->type = DATA_NONE;
    self->connected = false;
}
