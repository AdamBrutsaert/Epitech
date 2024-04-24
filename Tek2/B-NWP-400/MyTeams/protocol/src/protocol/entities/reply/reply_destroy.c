/*
** EPITECH PROJECT, 2024
** reply_destroy.c
** File description:
** reply_destroy.c
*/

#include "protocol/entities/reply.h"

#include "my/memory/allocation.h"

void reply_destroy(reply_t *reply)
{
    string_destroy(reply->thread_uuid);
    string_destroy(reply->user_uuid);
    string_destroy(reply->body);
    deallocate(reply);
}
