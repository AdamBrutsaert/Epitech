/*
** EPITECH PROJECT, 2024
** token_destroy.c
** File description:
** token_destroy.c
*/

#include "parsing/token.h"

#include "my/memory/allocation.h"

void token_destroy(token_t *self)
{
    string_destroy(self->value);
    deallocate(self);
}
