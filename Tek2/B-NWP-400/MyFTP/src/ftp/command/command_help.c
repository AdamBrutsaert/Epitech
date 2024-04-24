/*
** EPITECH PROJECT, 2024
** command_help.c
** File description:
** command_help.c
*/

#include "ftp/command.h"
#include "ftp/client.h"

bool command_help(client_t *client, __attribute__((unused)) char **args)
{
    control_t *ctrl = client_control(client);
    user_t *user = client_user(client);

    if (!user_is_authed(user))
        return control_send(ctrl, "530 Please login with USER and PASS.\r\n");
    return control_send(ctrl, "214-The following commands are recognized.\r\n"
        " USER PASS NOOP HELP\r\n214 Help OK.\r\n");
}
