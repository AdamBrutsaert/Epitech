/*
** EPITECH PROJECT, 2023
** reader_is_end.c
** File description:
** reader_is_end.c
*/

#include "shell/reader.h"

bool reader_is_end(reader_t *reader)
{
    return reader->current >= reader->length;
}
