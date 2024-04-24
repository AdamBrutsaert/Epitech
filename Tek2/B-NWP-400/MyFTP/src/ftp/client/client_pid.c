/*
** EPITECH PROJECT, 2024
** client_pid.c
** File description:
** client_pid.c
*/

#include "ftp/client.h"

pid_t client_pid(const client_t *self)
{
    return self->pid;
}
