/*
** EPITECH PROJECT, 2023
** reader_skip_line.c
** File description:
** reader_skip_line.c
*/

#include "asm/reader_impl.h"

void reader_skip_line(reader_t *reader)
{
    while (reader_peek(reader, 0) != '\n' && reader_peek(reader, 0) != '\0')
        reader_next(reader, 1);
}
