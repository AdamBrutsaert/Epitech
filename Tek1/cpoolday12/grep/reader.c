/*
** EPITECH PROJECT, 2022
** reader
** File description:
** Implementation of reader
*/

#include "reader.h"
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

void reader_create(reader_t *reader, char const *path)
{
    int fd = open(path, O_RDONLY);

    errno = errno == 11 ? 0 : errno;
    reader->path = path;
    reader->file = fd;
    reader->length = 0;
    reader->index = 0;
    reader->error = errno;
    reader->end = 0;
    errno = 0;
    if (!reader->error)
        read_some(reader);
}

void reader_create_stdin(reader_t *reader)
{
    errno = errno == 11 ? 0 : errno;
    reader->path = "stdin";
    reader->file = 0;
    reader->length = 0;
    reader->index = 0;
    reader->error = errno;
    reader->end = 0;
    errno = 0;
    if (!reader->error)
        read_some(reader);
}

void reader_destroy(reader_t *reader)
{
    close(reader->file);
}

void read_some(reader_t *reader)
{
    reader->length = read(reader->file, reader->buffer, BUFFER_CAPACITY);
    reader->error = errno;
    errno = 0;
    reader->end = reader->length == 0;
    reader->index = 0;
}
