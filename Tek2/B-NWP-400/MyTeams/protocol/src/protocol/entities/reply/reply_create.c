/*
** EPITECH PROJECT, 2024
** reply_create.c
** File description:
** reply_create.c
*/

#include "protocol/entities/reply.h"
#include "protocol/packet/type.h"

#include "my/memory/allocation.h"

reply_t *reply_create(
    const string_t *thread_uuid,
    const string_t *user_uuid,
    time_t timestamp,
    const string_t *body
)
{
    reply_t *self = allocate(sizeof(reply_t));

    self->thread_uuid = string_clone(thread_uuid);
    self->user_uuid = string_clone(user_uuid);
    self->timestamp = timestamp;
    self->body = string_clone_n(body, MAX_BODY_LENGTH);
    return self;
}
