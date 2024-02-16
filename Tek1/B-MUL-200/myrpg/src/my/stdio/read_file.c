/*
** EPITECH PROJECT, 2023
** read_file.c
** File description:
** read_file.c
*/

#include "my/stdio.h"

#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>

char *read_file(const char *path)
{
    int fd = open(path, O_RDONLY);
    char *content;

    if (fd == -1)
        return NULL;
    content = read_fd(fd);
    close(fd);
    return content;
}
