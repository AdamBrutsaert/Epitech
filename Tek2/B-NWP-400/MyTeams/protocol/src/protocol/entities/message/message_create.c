/*
** EPITECH PROJECT, 2024
** message_create.c
** File description:
** message_create.c
*/

#include "protocol/entities/message.h"
#include "protocol/packet/type.h"

#include "my/memory/allocation.h"

message_t *message_create(
    const string_t *from_uuid,
    const string_t *to_uuid,
    const string_t *message,
    const time_t timestamp
)
{
    message_t *self = allocate(sizeof(message_t));

    self->from_uuid = string_clone(from_uuid);
    self->to_uuid = string_clone(to_uuid);
    self->message = string_clone_n(message, MAX_BODY_LENGTH);
    self->timestamp = timestamp;
    return self;
}
