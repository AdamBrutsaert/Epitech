/*
** EPITECH PROJECT, 2024
** file_close.c
** File description:
** file_close.c
*/

#include "my/memory/file.h"

#include <unistd.h>

void file_close(file_t *self)
{
    if (FILE_OPENED(self))
        close(*self);
    *self = -1;
}
