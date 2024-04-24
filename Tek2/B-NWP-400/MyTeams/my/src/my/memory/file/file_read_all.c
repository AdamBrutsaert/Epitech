/*
** EPITECH PROJECT, 2024
** file_read_all.c
** File description:
** file_read_all.c
*/

#include "my/memory/file.h"

string_t *file_read_all(file_t *self)
{
    string_t *string = string_create();
    char buffer[1025];
    ssize_t bytes = file_read(self, buffer, 1024);

    while (bytes > 0) {
        buffer[bytes] = '\0';
        string_append_cstr(string, buffer);
        bytes = file_read(self, buffer, 1024);
    }
    return string;
}
