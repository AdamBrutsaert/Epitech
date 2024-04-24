/*
** EPITECH PROJECT, 2024
** user_is_authed.c
** File description:
** user_is_authed.c
*/

#include "ftp/user.h"

bool user_is_authed(user_t *self)
{
    return self->authed;
}
