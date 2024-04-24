/*
** EPITECH PROJECT, 2024
** thread_create.c
** File description:
** thread_create.c
*/

#include "protocol/entities/thread.h"
#include "protocol/packet/type.h"

#include "my/memory/allocation.h"

thread_t *thread_create(const thread_create_args_t *args)
{
    thread_t *self = allocate(sizeof(thread_t));

    self->uuid = string_create_random_uuid();
    self->channel_uuid = string_clone(args->channel_uuid);
    self->user_uuid = string_clone(args->user_uuid);
    self->timestamp = args->timestamp;
    self->title = string_clone_n(args->title, MAX_NAME_LENGTH);
    self->body = string_clone_n(args->body, MAX_BODY_LENGTH);
    return self;
}
