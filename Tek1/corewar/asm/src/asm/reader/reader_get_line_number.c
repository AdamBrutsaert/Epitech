/*
** EPITECH PROJECT, 2023
** reader_get_line_number.c
** File description:
** reader_get_line_number.c
*/

#include "asm/reader_impl.h"

size_t reader_get_line_number(reader_t *reader)
{
    return reader->line + 1;
}
