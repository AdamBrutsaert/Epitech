/*
** EPITECH PROJECT, 2023
** my_readfile.c
** File description:
** my_readfile.c
*/

#include "my/stdio.h"

#include <unistd.h>
#include <fcntl.h>

char *my_readfile(const char *file)
{
    int fd = open(file, O_RDONLY);
    char *content;

    if (fd == -1)
        return NULL;
    content = my_readfd(fd);
    close(fd);
    return content;
}
