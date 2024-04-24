/*
** EPITECH PROJECT, 2024
** string_create_from_buffer.c
** File description:
** string_create_from_buffer.c
*/

#include "my/memory/string.h"

string_t *string_create_from_buffer(const void *buffer, size_t size)
{
    string_t *self = vec_create(sizeof(char));

    vec_push_back_some(self, buffer, size);
    vec_push_back(self, &(char){0});
    return self;
}
