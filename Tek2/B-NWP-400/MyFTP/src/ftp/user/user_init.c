/*
** EPITECH PROJECT, 2024
** user_init.c
** File description:
** user_init.c
*/

#include "ftp/user.h"

#include <stddef.h>

void user_init(user_t *self)
{
    self->name = NULL;
    self->authed = false;
}
