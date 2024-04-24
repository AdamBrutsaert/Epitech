/*
** EPITECH PROJECT, 2024
** packet_push_user_vec.c
** File description:
** packet_push_user_vec.c
*/

#include "protocol/entities/user.h"

void packet_push_user_vec(packet_t *self, const vec_t *users)
{
    for (size_t i = 0; i < VEC_LEN(users); i++)
        packet_push_user(self, *(user_t **)VEC_AT(users, i));
    packet_push_u64(self, VEC_LEN(users));
}
