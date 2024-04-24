/*
** EPITECH PROJECT, 2024
** reader_init.c
** File description:
** reader_init.c
*/

#include "parsing/reader.h"

#include "my/memory/allocation.h"

reader_t *reader_create(void)
{
    reader_t *reader = allocate(sizeof(reader_t));

    reader->buffer = vec_create(sizeof(uint8_t));
    reader->cursor = 0;
    return reader;
}
