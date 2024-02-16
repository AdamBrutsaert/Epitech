/*
** EPITECH PROJECT, 2023
** reader_match.c
** File description:
** reader_match.c
*/

#include "asm/reader_impl.h"
#include "my/string.h"

bool reader_match(reader_t *reader, const char *string)
{
    if (reader->cursor + my_strlen(string) > reader->length)
        return false;
    return !my_strncmp(
        reader->buffer + reader->cursor,
        string,
        my_strlen(string)
    );
}
