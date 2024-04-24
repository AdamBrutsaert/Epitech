/*
** EPITECH PROJECT, 2024
** sv_get_all_users.c
** File description:
** sv_get_all_users.c
*/

#include "my/memory/allocation.h"
#include "protocol/entities/user.h"
#include "protocol/packet/get_all_users.h"

void sv_get_all_users_packet_encode(
    sv_get_all_users_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_user_vec(packet, self->users);
}

bool sv_get_all_users_packet_decode(
    sv_get_all_users_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_user_vec(packet, &self->users)
        && packet_pop_u8(packet, &self->type);
}

void sv_get_all_users_packet_destroy(sv_get_all_users_packet_t *self)
{
    for (size_t i = 0; i < VEC_LEN(self->users); i++)
        user_destroy(*(user_t **)VEC_AT(self->users, i));
    vec_destroy(self->users);
    deallocate(self);
}
