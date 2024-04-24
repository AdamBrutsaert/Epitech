/*
** EPITECH PROJECT, 2024
** file_open.c
** File description:
** file_open.c
*/

#include "my/memory/file.h"

#include <fcntl.h>

bool file_open(file_t *self, const char *filename, file_mode_t mode)
{
    *self = open(filename, mode, 0644);
    return FILE_OPENED(self);
}
