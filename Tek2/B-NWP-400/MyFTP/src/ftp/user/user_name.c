/*
** EPITECH PROJECT, 2024
** user_name.c
** File description:
** user_name.c
*/

#include "ftp/user.h"

const char *user_name(user_t *self)
{
    return self->name;
}
