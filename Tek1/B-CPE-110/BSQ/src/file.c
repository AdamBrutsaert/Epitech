/*
** EPITECH PROJECT, 2022
** file.c
** File description:
** file.c
*/

#include "file.h"

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int8_t file_open(file_t *file, char const *path)
{
    struct stat stats;

    if (stat(path, &stats) < 0)
        return 0;
    file->path = path;
    file->fd = open(path, O_RDONLY);
    file->length = stats.st_size;
    if (!S_ISREG(stats.st_mode))
        file_close(file);
    return file->fd >= 0 && S_ISREG(stats.st_mode);
}

void file_close(file_t *file)
{
    close(file->fd);
}

int8_t file_read(file_t *file, char *buffer)
{
    ssize_t bytes_read = 0;
    ssize_t length = 0;

    do {
        length += bytes_read;
        bytes_read = read(file->fd, buffer + length, file->length - length);
    } while (bytes_read > 0);
    buffer[length] = '\0';
    return !bytes_read;
}
