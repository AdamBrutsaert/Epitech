/*
** EPITECH PROJECT, 2024
** state_get_thread_by_uuid.c
** File description:
** state_get_thread_by_uuid.c
*/

#include "state.h"

thread_t *state_get_thread_by_uuid(state_t *self, const string_t *uuid)
{
    thread_t *thread;

    for (size_t i = 0; i < VEC_LEN(self->threads); i++) {
        thread = *(thread_t **)VEC_AT(self->threads, i);
        if (!string_compare(thread->uuid, uuid))
            return thread;
    }
    return nullptr;
}
