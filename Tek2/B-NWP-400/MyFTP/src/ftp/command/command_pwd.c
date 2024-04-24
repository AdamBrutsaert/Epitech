/*
** EPITECH PROJECT, 2024
** command_pwd.c
** File description:
** command_pwd.c
*/

#include "ftp/command.h"
#include "ftp/client.h"

bool command_pwd(client_t *client, __attribute__((unused)) char **args)
{
    user_t *user = client_user(client);
    path_t *path = client_path(client);
    control_t *ctrl = client_control(client);

    if (!user_is_authed(user))
        return control_send(ctrl, "530 Please login with USER and PASS.\r\n");
    return control_send(ctrl, "257 \"")
        && control_send(ctrl, path_get(path))
        && control_send(ctrl, "\" is the current directory.\r\n");
}
