/*
** EPITECH PROJECT, 2024
** message_destroy.c
** File description:
** message_destroy.c
*/

#include "protocol/entities/message.h"

#include "my/memory/allocation.h"

void message_destroy(message_t *self)
{
    string_destroy(self->from_uuid);
    string_destroy(self->to_uuid);
    string_destroy(self->message);
    deallocate(self);
}
