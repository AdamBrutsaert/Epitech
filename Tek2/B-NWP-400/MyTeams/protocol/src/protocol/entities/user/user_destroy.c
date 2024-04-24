/*
** EPITECH PROJECT, 2024
** user_destroy.c
** File description:
** user_destroy.c
*/

#include "protocol/entities/user.h"

#include "my/memory/allocation.h"

void user_destroy(user_t *self)
{
    string_destroy(self->name);
    string_destroy(self->uuid);
    deallocate(self);
}
