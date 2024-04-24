/*
** EPITECH PROJECT, 2024
** client_quit.c
** File description:
** client_quit.c
*/

#include "ftp/client.h"

void client_quit(client_t *self)
{
    self->quit = true;
}
