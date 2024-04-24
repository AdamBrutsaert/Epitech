/*
** EPITECH PROJECT, 2024
** state_restore_users.c
** File description:
** state_restore_users.c
*/

#include "state.h"

#include "myteams/logging_server.h"
#include "my/memory/file.h"

static bool user_already_exist(state_t *self, user_t *user)
{
    user_t *current;

    for (size_t i = 0; i < VEC_LEN(self->users); i++) {
        current = *(user_t **)VEC_AT(self->users, i);
        if (string_compare(current->uuid, user->uuid) == 0)
            return true;
        if (string_compare(current->name, user->name) == 0)
            return true;
    }
    return false;
}

static void parse_line(state_t *self, string_t *line)
{
    user_t *user = user_deserialize(line);

    if (user == nullptr)
        return;
    if (user_already_exist(self, user)) {
        user_destroy(user);
        return;
    }
    state_add_user(self, user);
    server_event_user_loaded(
        STRING_CDATA(user->uuid),
        STRING_CDATA(user->name)
    );
}

void state_restore_users(state_t *self)
{
    file_t *file = file_create();
    string_t *content;
    vec_t *lines;

    if (!file_open(file, "users.myteams", FILE_MODE_READ_ONLY)) {
        file_destroy(file);
        return;
    }
    content = file_read_all(file);
    file_destroy(file);
    lines = string_split_escaped(content, '\n');
    for (size_t i = 0; i < VEC_LEN(lines); i++)
        parse_line(self, *(string_t **)VEC_AT(lines, i));
    string_destroy(content);
    string_destroy_vec(lines);
}
