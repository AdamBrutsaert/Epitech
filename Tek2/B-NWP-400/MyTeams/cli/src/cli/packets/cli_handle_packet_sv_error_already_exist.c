/*
** EPITECH PROJECT, 2024
** cli_handle_packet_sv_error_already_exist.c
** File description:
** cli_handle_packet_sv_error_already_exist.c
*/

#include "cli.h"

#include "myteams/logging_client.h"

void cli_handle_packet_sv_error_already_exist(
    __attribute__((unused)) cli_t *self,
    __attribute__((unused)) sv_error_already_exist_packet_t *packet
)
{
    client_error_already_exist();
}
