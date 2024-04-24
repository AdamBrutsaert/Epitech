/*
** EPITECH PROJECT, 2024
** command_pasv.c
** File description:
** command_pasv.c
*/

#include "ftp/command.h"
#include "ftp/client.h"

static bool send_response(control_t *ctrl, ipv4_address_t *addr)
{
    return control_send(ctrl, "227 Entering Passive Mode (")
        && control_send_uint(ctrl, addr->address >> 24 & 0xFF)
        && control_send(ctrl, ",")
        && control_send_uint(ctrl, addr->address >> 16 & 0xFF)
        && control_send(ctrl, ",")
        && control_send_uint(ctrl, addr->address >> 8 & 0xFF)
        && control_send(ctrl, ",")
        && control_send_uint(ctrl, addr->address & 0xFF)
        && control_send(ctrl, ",")
        && control_send_uint(ctrl, addr->port >> 8 & 0xFF)
        && control_send(ctrl, ",")
        && control_send_uint(ctrl, addr->port & 0xFF)
        && control_send(ctrl, ").\r\n");
}

bool command_pasv(client_t *client, __attribute__((unused)) char **args)
{
    user_t *user = client_user(client);
    control_t *ctrl = client_control(client);
    data_t *data = client_data(client);
    ipv4_address_t addr;

    if (!user_is_authed(user))
        return control_send(ctrl, "530 Please login with USER and PASS.\r\n");
    if (!data_passive(data, &addr))
        return control_send(ctrl, "425 Can't open data connection.\r\n");
    return send_response(ctrl, &addr);
}
