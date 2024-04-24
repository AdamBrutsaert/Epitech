/*
** EPITECH PROJECT, 2024
** command_cwd.c
** File description:
** command_cwd.c
*/

#include "ftp/command.h"
#include "ftp/client.h"

bool command_cwd(client_t *client, char **args)
{
    user_t *user = client_user(client);
    path_t *path = client_path(client);
    control_t *ctrl = client_control(client);

    if (!user_is_authed(user))
        return control_send(ctrl, "530 Please login with USER and PASS.\r\n");
    if (!path_change(path, args[1] == NULL ? "" : args[1]))
        return control_send(ctrl, "550 Failed to change directory.\r\n");
    return control_send(ctrl, "250 Directory successfully changed.\r\n");
}
