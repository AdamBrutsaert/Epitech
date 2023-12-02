/*
** EPITECH PROJECT, 2023
** file_read.c
** File description:
** file_read.c
*/

#include "file.h"
#include "file/file.h"
#include <unistd.h>

int64_t file_read(file_t *file, char *buffer, int64_t bytes)
{
    int64_t read_bytes = 0;
    int64_t total_read_bytes = 0;

    do {
        total_read_bytes += read_bytes;
        read_bytes = read(file->fd, buffer, bytes - total_read_bytes);
    } while (read_bytes > 0 && total_read_bytes < bytes);
    return total_read_bytes;
}
