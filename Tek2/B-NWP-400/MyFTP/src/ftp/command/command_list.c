/*
** EPITECH PROJECT, 2024
** command_list.c
** File description:
** command_list.c
*/

#include "ftp/command.h"
#include "ftp/client.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static bool send_data(tcp_stream_t *stream, const char *path)
{
    FILE *fp;
    char *cmd = calloc(strlen(path) + 50, sizeof(char));

    if (cmd == NULL)
        return false;
    strcat(cmd, "ls -ln ");
    strcat(cmd, path);
    strcat(cmd, " 2>/dev/null | tail -n +2");
    fp = popen(cmd, "r");
    if (fp == NULL) {
        free(cmd);
        return false;
    }
    for (char c = fgetc(fp); c != EOF; c = fgetc(fp))
        tcp_stream_write(stream, &c, 1);
    pclose(fp);
    free(cmd);
    return true;
}

static pid_t fork_and_send(client_t *client)
{
    data_t *data = client_data(client);
    path_t *path = client_path(client);
    pid_t pid = fork();

    if (pid != 0)
        return pid;
    if (!send_data(&data->stream, path_get(path)))
        exit(1);
    exit(0);
}

static bool on_handling_command(client_t *client)
{
    user_t *user = client_user(client);
    control_t *ctrl = client_control(client);
    data_t *data = client_data(client);

    if (!user_is_authed(user))
        return control_send(ctrl, "530 Please login with USER and PASS.\r\n");
    if (data_type(data) == DATA_NONE)
        return control_send(ctrl, "425 Use PORT or PASV first.\r\n");
    client_set_state(client, CLIENT_WAITING_DATA_CONNECTION);
    return true;
}

static bool on_waiting_for_data_connection(client_t *client)
{
    data_t *data = client_data(client);
    control_t *ctrl = client_control(client);
    pid_t pid;

    if (!data_is_connected(data))
        return control_send(ctrl, "425 Failed to establish connection.\r\n");
    if (!control_send(ctrl, "150 Here comes the directory listing.\r\n"))
        return false;
    pid = fork_and_send(client);
    if (pid == -1)
        return false;
    client_set_pid(client, pid);
    client_set_state(client, CLIENT_WAITING_CHILD_PROCESS);
    return true;
}

static bool on_waiting_for_child_process(client_t *client)
{
    control_t *ctrl = client_control(client);

    client_set_state(client, CLIENT_HANDLING_COMMAND);
    if (WEXITSTATUS(client_child_status(client)) == 0)
        return control_send(ctrl, "226 Transfer completed\r\n");
    return control_send(ctrl, "500 Failed to send directory.\r\n");
}

bool command_list(client_t *client, __attribute__((unused)) char **args)
{
    if (client_state(client) == CLIENT_HANDLING_COMMAND)
        return on_handling_command(client);
    if (client_state(client) == CLIENT_WAITING_DATA_CONNECTION)
        return on_waiting_for_data_connection(client);
    if (client_state(client) == CLIENT_WAITING_CHILD_PROCESS)
        return on_waiting_for_child_process(client);
    return true;
}
