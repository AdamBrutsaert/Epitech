/*
** EPITECH PROJECT, 2024
** packet_push_user.c
** File description:
** packet_push_user.c
*/

#include "protocol/entities/user.h"

void packet_push_user(packet_t *self, const user_t *user)
{
    packet_push_string(self, user->uuid);
    packet_push_string(self, user->name);
    packet_push_u64(self, user->connections);
}
