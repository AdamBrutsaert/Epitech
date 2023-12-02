/*
** EPITECH PROJECT, 2023
** reader_create.c
** File description:
** reader_create.c
*/

#include "shell/reader.h"
#include "my/memory.h"

#include <stdlib.h>

reader_t *reader_create(void)
{
    reader_t *reader = malloc(sizeof(reader_t));

    if (reader == NULL)
        return NULL;
    my_memset(reader, 0, sizeof(reader_t));
    return reader;
}
