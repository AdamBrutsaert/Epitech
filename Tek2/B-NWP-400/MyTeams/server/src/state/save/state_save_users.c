/*
** EPITECH PROJECT, 2024
** state_save_users.c
** File description:
** state_save_users.c
*/

#include "state.h"

#include "my/memory/file.h"

void state_save_users(state_t *self)
{
    file_t *file = file_create();
    user_t *user;
    string_t *line;

    if (!file_open(file, "users.myteams",
        FILE_MODE_WRITE_ONLY | FILE_MODE_CREATE | FILE_MODE_TRUNC)) {
        file_destroy(file);
        return;
    }
    for (size_t i = 0; i < VEC_LEN(self->users); i++) {
        user = *(user_t **)VEC_AT(self->users, i);
        line = user_serialize(user);
        file_write_all(file, STRING_CDATA(line), STRING_LEN(line));
        string_destroy(line);
    }
    file_destroy(file);
}
