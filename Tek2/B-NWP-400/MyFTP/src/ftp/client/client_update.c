/*
** EPITECH PROJECT, 2024
** client_update.c
** File description:
** client_update.c
*/

#include "ftp/client.h"
#include "utils/parsing.h"
#include "ftp/command.h"

#include <stdlib.h>
#include <sys/wait.h>

static bool parse_command(client_t *self)
{
    char *command = control_get_command(&self->control);

    if (command == NULL)
        return false;
    free_args_array(self->command_args);
    self->command_args = parse_args_from_string(command);
    if (self->command_args == NULL) {
        free(command);
        return false;
    }
    self->command = command_parse(self->command_args);
    free(command);
    return self->command != NULL;
}

static bool client_handling_command(
    client_t *self,
    socket_selector_t *selector
)
{
    if (!data_update(&self->data, selector))
        return false;
    if (!control_update(&self->control, selector))
        return false;
    if (self->quit && !control_need_write(&self->control))
        return false;
    if (control_has_command(&self->control)
        && (!parse_command(self) || !self->command(self, self->command_args)))
        return false;
    return true;
}

static bool client_waiting_data_connection(
    client_t *self,
    socket_selector_t *selector
)
{
    if (!data_update(&self->data, selector))
        return false;
    if (data_type(&self->data) == DATA_ACTIVE) {
        data_connect(&self->data);
        return self->command(self, self->command_args);
    }
    if (data_is_connected(&self->data))
        return self->command(self, self->command_args);
    return true;
}

static bool client_waiting_child_process(client_t *self)
{
    pid_t pid = waitpid(self->pid, &self->child_status, WNOHANG);

    if (pid == -1)
        return false;
    if (pid == 0)
        return true;
    if (!self->command(self, self->command_args))
        return false;
    self->pid = -1;
    data_disconnect(&self->data);
    return true;
}

void client_update(client_t *self, socket_selector_t *selector)
{
    if (self->error)
        return;
    if (self->state == CLIENT_HANDLING_COMMAND
        && !client_handling_command(self, selector))
        self->error = true;
    if (self->state == CLIENT_WAITING_DATA_CONNECTION
        && !client_waiting_data_connection(self, selector))
        self->error = true;
    if (self->state == CLIENT_WAITING_CHILD_PROCESS
        && !client_waiting_child_process(self))
        self->error = true;
}
