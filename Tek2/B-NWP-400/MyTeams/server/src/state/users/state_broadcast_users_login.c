/*
** EPITECH PROJECT, 2024
** state_broadcast_users_login.c
** File description:
** state_broadcast_users_login.c
*/

#include "state.h"

void state_broadcast_users_login(state_t *self, user_t *user)
{
    sv_user_logged_in_packet_t packet = {
        .type = PACKET_TYPE_SV_USER_LOGGED_IN,
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
