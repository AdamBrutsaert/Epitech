/*
** EPITECH PROJECT, 2024
** command_stor.c
** File description:
** command_stor.c
*/

#include "ftp/command.h"
#include "ftp/client.h"
#include "utils/parsing.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

static bool full_write(int fd, const char *buffer, ssize_t size)
{
    ssize_t written = 0;
    ssize_t bytes;

    while (written < size) {
        bytes = write(fd, buffer + written, size - written);
        if (bytes <= 0)
            return false;
        written += bytes;
    }
    return true;
}

static bool store_file(tcp_stream_t *stream, char *path)
{
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char buffer[1024];
    ssize_t bytes;

    if (fd == -1)
        return false;
    bytes = tcp_stream_read(stream, buffer, 1024);
    while (bytes > 0) {
        if (!full_write(fd, buffer, bytes)) {
            close(fd);
            return false;
        }
        bytes = tcp_stream_read(stream, buffer, 1024);
    }
    close(fd);
    return true;
}

static char *get_path(client_t *client, char *path)
{
    char *cwd = client_path(client)->path;
    char *rel_path;
    char *true_path;

    if (path[0] == '/')
        return strdup(path);
    rel_path = calloc(strlen(cwd) + strlen(path) + 2, sizeof(char));
    if (rel_path == NULL)
        return NULL;
    strcat(rel_path, cwd);
    strcat(rel_path, "/");
    strcat(rel_path, path);
    true_path = parse_path(rel_path);
    if (true_path == NULL) {
        free(rel_path);
        return false;
    }
    free(rel_path);
    return true_path;
}

static pid_t fork_and_store(client_t *client, char *path)
{
    data_t *data = client_data(client);
    char *full_path = get_path(client, path);
    pid_t pid;

    if (full_path == NULL)
        return -1;
    pid = fork();
    if (pid != 0)
        return pid;
    if (!store_file(&data->stream, full_path))
        exit(1);
    exit(0);
}

static bool on_handling_command(client_t *client, char *path)
{
    user_t *user = client_user(client);
    control_t *ctrl = client_control(client);
    data_t *data = client_data(client);
    const char *root = client_path(client)->root;
    char *true_path = path == NULL ? NULL : get_path(client, path);

    if (!user_is_authed(user))
        return control_send(ctrl, "530 Please login with USER and PASS.\r\n");
    if (true_path == NULL || strncmp(true_path, root, strlen(root)) != 0)
        return control_send(ctrl, "550 Failed to store file.\r\n");
    if (data_type(data) == DATA_NONE)
        return control_send(ctrl, "425 Use PORT or PASV first.\r\n");
    client_set_state(client, CLIENT_WAITING_DATA_CONNECTION);
    return true;
}

static bool on_waiting_for_data_connection(client_t *client, char *path)
{
    data_t *data = client_data(client);
    control_t *ctrl = client_control(client);
    pid_t pid;

    if (!data_is_connected(data))
        return control_send(ctrl, "425 Failed to establish connection.\r\n");
    if (!control_send(ctrl, "150 Connection established.\r\n"))
        return false;
    pid = fork_and_store(client, path);
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
    return control_send(ctrl, "500 Failed to store.\r\n");
}

bool command_stor(client_t *client, char **args)
{
    if (client_state(client) == CLIENT_HANDLING_COMMAND)
        return on_handling_command(client, args[1]);
    if (client_state(client) == CLIENT_WAITING_DATA_CONNECTION)
        return on_waiting_for_data_connection(client, args[1]);
    if (client_state(client) == CLIENT_WAITING_CHILD_PROCESS)
        return on_waiting_for_child_process(client);
    return true;
}
