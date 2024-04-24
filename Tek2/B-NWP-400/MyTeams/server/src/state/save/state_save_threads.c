/*
** EPITECH PROJECT, 2024
** state_save_threads.c
** File description:
** state_save_threads.c
*/

#include "state.h"

#include "my/memory/file.h"

void state_save_threads(state_t *self)
{
    file_t *file = file_create();
    thread_t *thread;
    string_t *line;

    if (!file_open(file, "threads.myteams",
        FILE_MODE_WRITE_ONLY | FILE_MODE_CREATE | FILE_MODE_TRUNC)) {
        file_destroy(file);
        return;
    }
    for (size_t i = 0; i < VEC_LEN(self->threads); i++) {
        thread = *(thread_t **)VEC_AT(self->threads, i);
        line = thread_serialize(thread);
        file_write_all(file, STRING_CDATA(line), STRING_LEN(line));
        string_destroy(line);
    }
    file_destroy(file);
}
