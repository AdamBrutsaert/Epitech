/*
** EPITECH PROJECT, 2023
** reader_get_back.c
** File description:
** reader_get_back.c
*/

#include "shell/reader.h"
#include "my/string.h"

char *reader_get_back(reader_t *reader, size_t bytes)
{
    if (reader->current < bytes)
        return NULL;
    return my_strndup(reader->buffer + reader->current - bytes, bytes);
}
