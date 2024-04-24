/*
** EPITECH PROJECT, 2024
** state_broadcast_team_created.c
** File description:
** state_broadcast_team_created.c
*/

#include "state.h"

void state_broadcast_team_created(state_t *self, team_t *team)
{
    sv_create_team_packet_t packet = {
        .type = PACKET_TYPE_SV_CREATE_TEAM,
        .team = team
    };

    for (size_t i = 0; i < VEC_LEN(self->users); i++) {
        state_send_packet_to_user(
            self,
            *(user_t **)VEC_AT(self->users, i),
            (cl_sv_packet_t *)&packet
        );
    }
}
