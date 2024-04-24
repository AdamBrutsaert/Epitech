/*
** EPITECH PROJECT, 2024
** state_restore_messages.c
** File description:
** state_restore_messages.c
*/

#include "state.h"

#include "my/memory/file.h"

#include <stdio.h>

static void parse_line(state_t *self, string_t *line)
{
    message_t *msg = message_deserialize(line);

    if (msg == nullptr)
        return;
    if (!state_get_user_by_uuid(self, msg->from_uuid)
        || !state_get_user_by_uuid(self, msg->to_uuid)) {
        message_destroy(msg);
        return;
    }
    state_add_message(self, msg);
    printf("[Restored] Message from %s to %s at %zu: %s\n",
        STRING_CDATA(msg->from_uuid), STRING_CDATA(msg->to_uuid),
        msg->timestamp, STRING_CDATA(msg->message)
    );
}

void state_restore_messages(state_t *self)
{
    file_t *file = file_create();
    string_t *content;
    vec_t *lines;

    if (!file_open(file, "messages.myteams", FILE_MODE_READ_ONLY)) {
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
