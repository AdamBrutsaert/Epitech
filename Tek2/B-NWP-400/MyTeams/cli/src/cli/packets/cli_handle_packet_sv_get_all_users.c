/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_get_all_users.c
** File description:
** cli_handle_packet_sv_get_all_users.c
*/

#include "cli.h"
#include "myteams/logging_client.h"
#include "protocol/entities/user.h"

void cli_handle_packet_sv_get_all_users(
    __attribute__((unused)) cli_t *self,
    sv_get_all_users_packet_t *packet
)
{
    user_t *user;

    for (size_t i = 0; i < VEC_LEN(packet->users); i++) {
        user = *(user_t **)VEC_AT(packet->users, i);
        client_print_users(
            STRING_CDATA(user->uuid),
            STRING_CDATA(user->name),
            !!user->connections
        );
    }
}
