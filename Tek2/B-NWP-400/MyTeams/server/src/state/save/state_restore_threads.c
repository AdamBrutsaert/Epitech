/*
** EPITECH PROJECT, 2024
** state_restore_threads.c
** File description:
** state_restore_threads.c
*/

#include "state.h"

#include "my/memory/file.h"

#include <stdio.h>

static bool check_thread_already_exist(state_t *self, thread_t *thread)
{
    thread_t *current;

    for (size_t i = 0; i < VEC_LEN(self->threads); i++) {
        current = *(thread_t **)VEC_AT(self->threads, i);
        if (string_compare(current->channel_uuid, thread->channel_uuid) != 0)
            continue;
        if (string_compare(current->uuid, thread->uuid) == 0)
            return true;
    }
    return false;
}

static void parse_line(state_t *self, string_t *line)
{
    thread_t *thread = thread_deserialize(line);

    if (thread == nullptr)
        return;
    if (!state_get_channel_by_uuid(self, thread->channel_uuid)
        || !state_get_user_by_uuid(self, thread->user_uuid)
        || check_thread_already_exist(self, thread)) {
        thread_destroy(thread);
        return;
    }
    state_add_thread(self, thread);
    printf("[Restored] Thread %s of channel %s by %s named %s at %zu: %s\n",
        STRING_CDATA(thread->uuid), STRING_CDATA(thread->channel_uuid),
        STRING_CDATA(thread->user_uuid), STRING_CDATA(thread->title),
        thread->timestamp, STRING_CDATA(thread->body)
    );
}

void state_restore_threads(state_t *self)
{
    file_t *file = file_create();
    string_t *content;
    vec_t *lines;

    if (!file_open(file, "threads.myteams", FILE_MODE_READ_ONLY)) {
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
