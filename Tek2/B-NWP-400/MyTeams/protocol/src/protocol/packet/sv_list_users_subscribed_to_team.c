/*
** EPITECH PROJECT, 2024
** sv_list_users_subscribed_to_team.c
** File description:
** sv_list_users_subscribed_to_team.c
*/

#include "protocol/packet/list_users_subscribed_to_team.h"

#include "protocol/entities/user.h"
#include "my/memory/allocation.h"

void sv_list_users_subscribed_to_team_packet_encode(
    sv_list_users_subscribed_to_team_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_user_vec(packet, self->users);
}

bool sv_list_users_subscribed_to_team_packet_decode(
    sv_list_users_subscribed_to_team_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_user_vec(packet, &self->users)
        && packet_pop_u8(packet, &self->type);
}

void sv_list_users_subscribed_to_team_packet_destroy(
    sv_list_users_subscribed_to_team_packet_t *self
)
{
    for (size_t i = 0; i < VEC_LEN(self->users); i++)
        user_destroy(*(user_t **)VEC_AT(self->users, i));
    vec_destroy(self->users);
    deallocate(self);
}
