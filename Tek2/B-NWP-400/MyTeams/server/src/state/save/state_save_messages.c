/*
** EPITECH PROJECT, 2024
** state_save_messages.c
** File description:
** state_save_messages.c
*/

#include "state.h"

#include "my/memory/file.h"

void state_save_messages(state_t *self)
{
    file_t *file = file_create();
    string_t *data;

    if (!file_open(file, "messages.myteams",
        FILE_MODE_WRITE_ONLY | FILE_MODE_CREATE | FILE_MODE_TRUNC)) {
        file_destroy(file);
        return;
    }
    for (size_t i = 0; i < VEC_LEN(self->messages); i++) {
        data = message_serialize(*(message_t **)VEC_AT(self->messages, i));
        file_write_all(file, STRING_CDATA(data), STRING_LEN(data));
        string_destroy(data);
    }
    file_destroy(file);
}
