/*
** EPITECH PROJECT, 2024
** state_restore_replies.c
** File description:
** state_restore_replies.c
*/

#include "state.h"

#include "my/memory/file.h"

#include <stdio.h>

static void parse_line(state_t *self, string_t *line)
{
    reply_t *reply = reply_deserialize(line);

    if (reply == nullptr)
        return;
    if (!state_get_thread_by_uuid(self, reply->thread_uuid)
        || !state_get_user_by_uuid(self, reply->user_uuid)) {
        reply_destroy(reply);
        return;
    }
    state_add_reply(self, reply);
    printf("[Restored] Reply to thread %s by %s at %zu: %s\n",
        STRING_CDATA(reply->thread_uuid), STRING_CDATA(reply->user_uuid),
        reply->timestamp, STRING_CDATA(reply->body)
    );
}

void state_restore_replies(state_t *self)
{
    file_t *file = file_create();
    string_t *content;
    vec_t *lines;

    if (!file_open(file, "replies.myteams", FILE_MODE_READ_ONLY)) {
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
