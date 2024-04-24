/*
** EPITECH PROJECT, 2024
** state_save_channels.c
** File description:
** state_save_channels.c
*/

#include "state.h"

#include "my/memory/file.h"

void state_save_channels(state_t *self)
{
    file_t *file = file_create();
    channel_t *channel;
    string_t *line;

    if (!file_open(file, "channels.myteams",
        FILE_MODE_WRITE_ONLY | FILE_MODE_CREATE | FILE_MODE_TRUNC)) {
        file_destroy(file);
        return;
    }
    for (size_t i = 0; i < VEC_LEN(self->channels); i++) {
        channel = *(channel_t **)VEC_AT(self->channels, i);
        line = channel_serialize(channel);
        file_write_all(file, STRING_CDATA(line), STRING_LEN(line));
        string_destroy(line);
    }
    file_destroy(file);
}
