/*
** EPITECH PROJECT, 2024
** cl_create_team.c
** File description:
** cl_create_team.c
*/

#include "protocol/packet/create_team.h"
#include "my/memory/allocation.h"

void cl_create_team_packet_encode(
    cl_create_team_packet_t *self,
    packet_t *packet
)
{
    packet_push_u8(packet, self->type);
    packet_push_string(packet, self->name);
    packet_push_string(packet, self->description);
}

bool cl_create_team_packet_decode(
    cl_create_team_packet_t *self,
    packet_t *packet
)
{
    return packet_pop_string(packet, &self->description)
        && packet_pop_string(packet, &self->name)
        && packet_pop_u8(packet, &self->type);
}

void cl_create_team_packet_destroy(cl_create_team_packet_t *self)
{
    string_destroy(self->name);
    string_destroy(self->description);
    deallocate(self);
}
