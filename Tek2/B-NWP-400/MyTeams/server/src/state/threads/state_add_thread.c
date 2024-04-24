/*
** EPITECH PROJECT, 2024
** state_add_thread.c
** File description:
** state_add_thread.c
*/

#include "state.h"

void state_add_thread(state_t *self, thread_t *thread)
{
    vec_push_back(self->threads, &thread);
}
