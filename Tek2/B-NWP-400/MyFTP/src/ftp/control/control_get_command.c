/*
** EPITECH PROJECT, 2024
** control_get_command.c
** File description:
** control_get_command.c
*/

#include "ftp/control.h"

#include <stdlib.h>
#include <string.h>

static size_t find_end_of_command(control_t *self)
{
    size_t i = 0;
    const char *data = vec_data(&self->read_buffer);
    size_t length = vec_length(&self->read_buffer);

    for (; i + 1 < length; i++) {
        if (data[i] == '\r' && data[i + 1] == '\n')
            break;
    }
    return i;
}

char *control_get_command(control_t *self)
{
    char *command;
    size_t index = find_end_of_command(self);
    size_t length = vec_length(&self->read_buffer);

    if (index + 1 == length)
        return NULL;
    command = malloc(index + 3);
    if (command == NULL)
        return NULL;
    memcpy(command, vec_data(&self->read_buffer), index + 2);
    command[index + 2] = '\0';
    vec_pop_some_front(&self->read_buffer, index + 2);
    return command;
}
