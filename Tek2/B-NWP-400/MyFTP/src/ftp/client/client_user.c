/*
** EPITECH PROJECT, 2024
** client_user.c
** File description:
** client_user.c
*/

#include "ftp/client.h"

user_t *client_user(client_t *self)
{
    return &self->user;
}
