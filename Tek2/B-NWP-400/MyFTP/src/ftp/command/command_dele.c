/*
** EPITECH PROJECT, 2024
** command_dele.c
** File description:
** command_dele.c
*/

#include "ftp/command.h"
#include "ftp/client.h"
#include "utils/parsing.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static char *get_true_path(client_t *client, char *path)
{
    char *cwd = client_path(client)->path;
    char *rel_path = calloc(strlen(cwd) + strlen(path) + 2, sizeof(char));
    char *true_path;

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

static bool delete_relative_file(client_t *client, char *path)
{
    char *root = client_path(client)->root;
    char *true_path = get_true_path(client, path);
    bool status;

    if (true_path == NULL)
        return false;
    if (strncmp(true_path, root, strlen(root)) != 0) {
        free(true_path);
        return false;
    }
    status = remove(true_path) != -1;
    free(true_path);
    return status;
}

static bool delete_file(client_t *client, char *path)
{
    char *root = client_path(client)->root;

    if (path[0] == '/') {
        if (strncmp(path, root, strlen(root)) != 0)
            return false;
        return remove(path) != -1;
    }
    return delete_relative_file(client, path);
}

bool command_dele(client_t *client, char **args)
{
    control_t *ctrl = client_control(client);

    if (args[1] == NULL)
        return control_send(ctrl, "550 Failed to delete file.\r\n");
    return delete_file(client, args[1])
        ? control_send(ctrl, "250 File deleted.\r\n")
        : control_send(ctrl, "550 Failed to delete file.\r\n");
}
