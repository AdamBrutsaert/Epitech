/*
** EPITECH PROJECT, 2024
** connection_destroy.c
** File description:
** connection_destroy.c
*/

#include "protocol/entities/connection.h"

#include "my/memory/allocation.h"

void connection_destroy(connection_t *self)
{
    deallocate(self);
}
