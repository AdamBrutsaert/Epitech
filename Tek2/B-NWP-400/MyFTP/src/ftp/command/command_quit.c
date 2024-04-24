/*
** EPITECH PROJECT, 2024
** command_quit.c
** File description:
** command_quit.c
*/

#include "ftp/command.h"
#include "ftp/client.h"

bool command_quit(client_t *client, __attribute__((unused)) char **args)
{
    control_t *control = client_control(client);

    client_quit(client);
    return control_send(control, "221 Goodbye.\r\n");
}
