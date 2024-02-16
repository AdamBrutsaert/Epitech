/*
** EPITECH PROJECT, 2023
** reader_next.c
** File description:
** reader_next.c
*/

#include "shell/reader.h"

char reader_next(reader_t *reader)
{
    if (reader->current >= reader->length)
        return '\0';
    reader->current++;
    return reader->buffer[reader->current - 1];
}
