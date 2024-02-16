/*
** EPITECH PROJECT, 2023
** reader_push_file.c
** File description:
** reader_push_file.c
*/

#include "asm/reader_impl.h"
#include "my/memory.h"

#include <unistd.h>
#include <fcntl.h>

static bool read_file(reader_t *reader, int fd, size_t length)
{
    size_t total = 0;
    ssize_t bytes_read = 0;

    do {
        total += bytes_read;
        bytes_read = read(fd, reader->buffer + total, length - total);
    } while (bytes_read > 0 && total < length);
    return bytes_read >= 0;
}

bool reader_push_file(reader_t *reader, const char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    size_t length;

    if (fd == -1) {
        reader_error_open(filepath);
        return false;
    }
    length = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    reader->capacity = reader->length + length;
    reader->buffer = my_realloc(reader->buffer, reader->capacity);
    if (!read_file(reader, fd, length)) {
        reader_error_read(filepath);
        close(fd);
        return false;
    }
    reader->length += length;
    close(fd);
    return true;
}
