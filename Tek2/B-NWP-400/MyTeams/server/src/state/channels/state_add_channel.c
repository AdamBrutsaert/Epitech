/*
** EPITECH PROJECT, 2024
** state_add_channel.c
** File description:
** state_add_channel.c
*/

#include "state.h"

void state_add_channel(state_t *self, channel_t *channel)
{
    vec_push_back(self->channels, &channel);
}
