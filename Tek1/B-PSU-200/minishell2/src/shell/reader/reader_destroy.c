/*
** EPITECH PROJECT, 2023
** reader_destroy.c
** File description:
** reader_destroy.c
*/

#include "shell/reader.h"

#include <stdlib.h>

void reader_destroy(reader_t *reader)
{
    if (reader == NULL)
        return;
    reader_clear(reader);
    free(reader);
}
