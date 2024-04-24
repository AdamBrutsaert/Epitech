/*
** EPITECH PROJECT, 2024
** state_save_replies.c
** File description:
** state_save_replies.c
*/

#include "state.h"

#include "my/memory/file.h"

void state_save_replies(state_t *self)
{
    file_t *file = file_create();
    reply_t *reply;
    string_t *line;

    if (!file_open(file, "replies.myteams",
        FILE_MODE_WRITE_ONLY | FILE_MODE_CREATE | FILE_MODE_TRUNC)) {
        file_destroy(file);
        return;
    }
    for (size_t i = 0; i < VEC_LEN(self->replies); i++) {
        reply = *(reply_t **)VEC_AT(self->replies, i);
        line = reply_serialize(reply);
        file_write_all(file, STRING_CDATA(line), STRING_LEN(line));
        string_destroy(line);
    }
    file_destroy(file);
}
