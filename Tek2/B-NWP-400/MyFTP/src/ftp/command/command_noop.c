/*
** EPITECH PROJECT, 2024
** command_noop.c
** File description:
** command_noop.c
*/

#include "ftp/command.h"
#include "ftp/client.h"

bool command_noop(client_t *client, __attribute__((unused)) char **args)
{
    control_t *control = client_control(client);
    user_t *user = client_user(client);

    if (user_is_authed(user))
        return control_send(control, "200 NOOP ok.\r\n");
    return control_send(control, "530 Please login with USER and PASS.\r\n");
}
