/*
** EPITECH PROJECT, 2023
** read_fd.c
** File description:
** read_fd.c
*/

#include "my/stdio.h"
#include "my/memory.h"

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

static bool grow_buffer(char **buffer, size_t *capacity)
{
    size_t new_capacity = *capacity * 2 + !(*capacity);
    char *new_buffer = malloc(new_capacity + 1);

    if (new_buffer == NULL)
        return false;
    my_memcpy(new_buffer, *buffer, *capacity);
    free(*buffer);
    *buffer = new_buffer;
    *capacity = new_capacity;
    return true;
}

char *read_fd(int fd)
{
    char *buffer = NULL;
    size_t length = 0;
    size_t capacity = 0;
    ssize_t bytes_read = 0;

    do {
        length += bytes_read;
        if (length == capacity && !grow_buffer(&buffer, &capacity)) {
            free(buffer);
            return NULL;
        }
        bytes_read = read(fd, buffer + length, capacity - length);
    } while (bytes_read > 0);
    if (bytes_read == -1) {
        free(buffer);
        return NULL;
    }
    buffer[length] = '\0';
    return buffer;
}
