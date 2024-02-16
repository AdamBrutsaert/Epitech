/*
** EPITECH PROJECT, 2023
** save_write_char.c
** File description:
** save_write_char.c
*/

#include "save_impl.h"

#include <unistd.h>

void save_write_char(int fd, char value)
{
    write(fd, &value, sizeof(char));
}
