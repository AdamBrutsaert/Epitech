/*
** EPITECH PROJECT, 2024
** state_add_message.c
** File description:
** state_add_message.c
*/

#include "state.h"

void state_add_message(state_t *self, message_t *message)
{
    vec_push_back(self->messages, &message);
}
