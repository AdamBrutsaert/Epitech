/*
** EPITECH PROJECT, 2024
** user_deinit.c
** File description:
** user_deinit.c
*/

#include "ftp/user.h"

#include <stdlib.h>

void user_deinit(user_t *self)
{
    free(self->name);
}
