/*
** EPITECH PROJECT, 2023
** save_write_i32.c
** File description:
** save_write_i32.c
*/

#include "save_impl.h"

static int32_t my_abs(int32_t value)
{
    return value < 0 ? -value : value;
}

void save_write_i32(int fd, int32_t value)
{
    if (value < 0)
        save_write_char(fd, '-');
    if (value <= -10 || value >= 10)
        save_write_i32(fd, my_abs(value / 10));
    save_write_char(fd, my_abs(value % 10));
}
