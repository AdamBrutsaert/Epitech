/*
** EPITECH PROJECT, 2023
** reader_read_line.c
** File description:
** reader_read_line.c
*/

#include "shell/reader.h"
#include "my/string.h"

#include <stdio.h>
#include <stdlib.h>

void reader_read_line(reader_t *reader)
{
    char *line = NULL;
    size_t length = 0;

    reader_clear(reader);
    if (getline(&line, &length, stdin) == -1) {
        free(line);
        reader->eof = true;
        return;
    }
    reader->buffer = line;
    reader->length = my_strlen(line);
}
