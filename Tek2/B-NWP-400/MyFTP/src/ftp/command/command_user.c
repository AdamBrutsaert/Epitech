/*
** EPITECH PROJECT, 2024
** command_user.c
** File description:
** command_user.c
*/

#include "ftp/command.h"
#include "ftp/client.h"

bool command_user(client_t *client, char **args)
{
    control_t *control = client_control(client);
    user_t *user = client_user(client);

    if (user_is_authed(user))
        return control_send(control, "530 Can't change to another user.\r\n");
    return user_set_name(user, args[1])
        && control_send(control, "331 Please specify the password.\r\n");
}
