/*
** EPITECH PROJECT, 2024
** data_deinit.c
** File description:
** data_deinit.c
*/

#include "ftp/data.h"

void data_deinit(data_t *self)
{
    data_disconnect(self);
}
