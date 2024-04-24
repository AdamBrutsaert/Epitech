/*
** EPITECH PROJECT, 2024
** client_path.c
** File description:
** client_path.c
*/

#include "ftp/client.h"

path_t *client_path(client_t *self)
{
    return &self->path;
}
