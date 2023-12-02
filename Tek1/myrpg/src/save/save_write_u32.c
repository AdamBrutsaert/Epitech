/*
** EPITECH PROJECT, 2023
** save_write_u32.c
** File description:
** save_write_u32.c
*/

#include "save_impl.h"

void save_write_u32(int fd, uint32_t value)
{
    if (value >= 10)
        save_write_u32(fd, value / 10);
    save_write_char(fd, '0' + value % 10);
}
