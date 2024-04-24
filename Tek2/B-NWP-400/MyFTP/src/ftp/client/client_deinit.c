/*
** EPITECH PROJECT, 2024
** client_deinit.c
** File description:
** client_deinit.c
*/

#include "ftp/client.h"
#include "utils/parsing.h"

void client_deinit(client_t *self)
{
    control_deinit(&self->control);
    data_deinit(&self->data);
    user_deinit(&self->user);
    path_deinit(&self->path);
    free_args_array(self->command_args);
}
