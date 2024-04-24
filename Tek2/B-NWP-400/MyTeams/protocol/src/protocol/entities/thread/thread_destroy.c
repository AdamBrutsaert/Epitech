/*
** EPITECH PROJECT, 2024
** thread_destroy.c
** File description:
** thread_destroy.c
*/

#include "protocol/entities/thread.h"

#include "my/memory/allocation.h"

void thread_destroy(thread_t *thread)
{
    string_destroy(thread->uuid);
    string_destroy(thread->channel_uuid);
    string_destroy(thread->user_uuid);
    string_destroy(thread->title);
    string_destroy(thread->body);
    deallocate(thread);
}
