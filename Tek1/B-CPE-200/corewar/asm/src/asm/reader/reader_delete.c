/*
** EPITECH PROJECT, 2023
** reader_delete.c
** File description:
** reader_delete.c
*/

#include "asm/reader_impl.h"
#include "my/memory.h"

void reader_delete(reader_t *reader)
{
    my_free(reader->buffer);
    my_free(reader);
}
