/*
** EPITECH PROJECT, 2024
** command_cdup.c
** File description:
** command_cdup.c
*/

#include "ftp/command.h"
#include "ftp/client.h"

bool command_cdup(client_t *client, __attribute__((unused)) char **args)
{
    user_t *user = client_user(client);
    path_t *path = client_path(client);
    control_t *ctrl = client_control(client);

    if (!user_is_authed(user))
        return control_send(ctrl, "530 Please login with USER and PASS.\r\n");
    path_change_up(path);
    return control_send(ctrl, "200 Directory successfully changed.\r\n");
}
