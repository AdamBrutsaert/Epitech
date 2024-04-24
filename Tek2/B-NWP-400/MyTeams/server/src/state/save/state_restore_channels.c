/*
** EPITECH PROJECT, 2024
** state_restore_channels.c
** File description:
** state_restore_channels.c
*/

#include "state.h"

#include "my/memory/file.h"

#include <stdio.h>

static bool channel_already_exist(state_t *self, channel_t *channel)
{
    channel_t *current;

    for (size_t i = 0; i < VEC_LEN(self->channels); i++) {
        current = *(channel_t **)VEC_AT(self->channels, i);
        if (string_compare(current->team_uuid, channel->team_uuid) != 0)
            continue;
        if (string_compare(current->uuid, channel->uuid) == 0)
            return true;
        if (string_compare(current->name, channel->name) == 0)
            return true;
    }
    return false;
}

static void parse_line(state_t *self, string_t *line)
{
    channel_t *channel = channel_deserialize(line);

    if (channel == nullptr)
        return;
    if (!state_get_team_by_uuid(self, channel->team_uuid)) {
        channel_destroy(channel);
        return;
    }
    if (channel_already_exist(self, channel)) {
        channel_destroy(channel);
        return;
    }
    state_add_channel(self, channel);
    printf("[Restored] Channel %s of team %s named %s: %s\n",
        STRING_CDATA(channel->uuid), STRING_CDATA(channel->team_uuid),
        STRING_CDATA(channel->name), STRING_CDATA(channel->description)
    );
}

void state_restore_channels(state_t *self)
{
    file_t *file = file_create();
    string_t *content;
    vec_t *lines;

    if (!file_open(file, "channels.myteams", FILE_MODE_READ_ONLY)) {
        file_destroy(file);
        return;
    }
    content = file_read_all(file);
    file_destroy(file);
    lines = string_split(content, '\n');
    for (size_t i = 0; i < VEC_LEN(lines); i++)
        parse_line(self, *(string_t **)VEC_AT(lines, i));
    string_destroy(content);
    string_destroy_vec(lines);
}
