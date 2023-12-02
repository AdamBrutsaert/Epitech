/*
** EPITECH PROJECT, 2023
** reader_delete.c
** File description:
** reader_delete.c
*/

#include "shell/reader_impl.h"

#include <stdlib.h>

void reader_delete(reader_t *reader)
{
    if (reader == NULL)
        return;
    free(reader->buffer);
    free(reader);
}
