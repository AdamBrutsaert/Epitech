/*
** EPITECH PROJECT, 2024
** client_child_status.c
** File description:
** client_child_status.c
*/

#include "ftp/client.h"

pid_t client_child_status(const client_t *self)
{
    return self->child_status;
}
