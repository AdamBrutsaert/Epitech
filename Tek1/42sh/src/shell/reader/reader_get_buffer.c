/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-42sh-yanis.zeghiche
** File description:
** reader_get_buffer
*/

#include <string.h>

#include "shell/reader_impl.h"

char *reader_get_buffer(reader_t *reader)
{
    return strndup(reader->buffer, reader->length);
}
