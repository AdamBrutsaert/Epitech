/*
** EPITECH PROJECT, 2023
** reader_push.c
** File description:
** reader_push.c
*/

#include "shell/reader_impl.h"

#include <stdlib.h>
#include <string.h>

static bool grow(reader_t *reader, size_t length)
{
    size_t capacity = reader->capacity + !reader->capacity;
    char *buffer;

    while (capacity <= reader->length + length)
        capacity *= 2;
    buffer = realloc(reader->buffer, capacity);
    if (buffer == NULL)
        return false;
    reader->buffer = buffer;
    reader->capacity = capacity;
    return true;
}

bool reader_push(reader_t *reader, const char *string)
{
    size_t length = strlen(string);

    if (reader->length + length > reader->capacity && !grow(reader, length))
        return false;
    memcpy(reader->buffer + reader->length, string, length);
    reader->length += length;
    return true;
}
