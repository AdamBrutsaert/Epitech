/*
** EPITECH PROJECT, 2023
** reader_clear.c
** File description:
** reader_clear.c
*/

#include "asm/reader_impl.h"

void reader_clear(reader_t *reader)
{
    reader->length = 0;
    reader->cursor = 0;
    reader->line = 0;
}
