/*
** EPITECH PROJECT, 2024
** command_pass.c
** File description:
** command_pass.c
*/

#include "ftp/command.h"
#include "ftp/client.h"

bool command_pass(client_t *client, char **args)
{
    control_t *control = client_control(client);
    user_t *user = client_user(client);

    if (user_is_authed(user))
        return control_send(control, "230 Already logged in.\r\n");
    if (user_name(user) == NULL)
        return control_send(control, "503 Login with USER first.\r\n");
    user_authenticate(user, args[1]);
    if (user_is_authed(user))
        return control_send(control, "230 Login successful.\r\n");
    return control_send(control, "530 Login incorrect.\r\n");
}
