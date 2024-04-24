/*
** EPITECH PROJECT, 2024
** client_set_pid.c
** File description:
** client_set_pid.c
*/

#include "ftp/client.h"

void client_set_pid(client_t *self, pid_t pid)
{
    self->pid = pid;
}
