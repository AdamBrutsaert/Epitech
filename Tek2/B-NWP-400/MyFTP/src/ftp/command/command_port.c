/*
** EPITECH PROJECT, 2024
** command_port.c
** File description:
** command_port.c
*/

#include "ftp/command.h"
#include "ftp/client.h"
#include "utils/parsing.h"

bool command_port(client_t *client, char **args)
{
    user_t *user = client_user(client);
    control_t *ctrl = client_control(client);
    ipv4_address_t addr;

    if (!user_is_authed(user))
        return control_send(ctrl, "530 Please login with USER and PASS.\r\n");
    if (args[1] == NULL || args[2] != NULL || !parse_address(&addr, args[1]))
        return control_send(ctrl, "500 Illegal PORT command.\r\n");
    data_active(client_data(client), &addr);
    return control_send(ctrl, "200 PORT command successful.\r\n");
}
