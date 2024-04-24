/*
** EPITECH PROJECT, 2024
** command_destroy.c
** File description:
** command_destroy.c
*/

#include "parsing/parser.h"

#include "my/memory/allocation.h"

void command_destroy(command_t *self)
{
    string_destroy(self->name);
    for (size_t i = 0; i < VEC_LEN(self->arguments); i++)
        string_destroy(*(string_t **)VEC_AT(self->arguments, i));
    vec_destroy(self->arguments);
    deallocate(self);
}
