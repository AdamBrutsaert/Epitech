/*
** EPITECH PROJECT, 2024
** state_broadcast_users_logout.c
** File description:
** state_broadcast_users_logout.c
*/

#include "state.h"

void state_broadcast_users_logout(state_t *self, user_t *user)
{
    sv_user_logged_out_packet_t packet = {
        .type = PACKET_TYPE_SV_USER_LOGGED_OUT,
        .uuid = user->uuid,
        .name = user->name,
    };

    for (size_t i = 0; i < VEC_LEN(self->users); i++) {
        state_send_packet_to_user(
            self,
            *(user_t **)VEC_AT(self->users, i),
            (cl_sv_packet_t *)&packet
        );
    }
}
