/*
** EPITECH PROJECT, 2023
** reader_clear.c
** File description:
** reader_clear.c
*/

#include "shell/reader.h"

#include <stdlib.h>

void reader_clear(reader_t *reader)
{
    free(reader->buffer);
    reader->buffer = NULL;
    reader->current = 0;
    reader->length = 0;
}
