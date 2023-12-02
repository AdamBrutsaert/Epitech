/*
** EPITECH PROJECT, 2022
** file_destroy.c
** File description:
** file_destroy.c
*/

#include "my/file.h"

#include <unistd.h>

void file_destroy(file_t *file)
{
    if (!file)
        return;
    close(file->fd);
}
