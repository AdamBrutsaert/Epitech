/*
** EPITECH PROJECT, 2024
** state_add_reply.c
** File description:
** state_add_reply.c
*/

#include "state.h"

void state_add_reply(state_t *self, reply_t *reply)
{
    vec_push_back(self->replies, &reply);
}
