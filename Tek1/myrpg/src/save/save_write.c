/*
** EPITECH PROJECT, 2023
** save_write.c
** File description:
** save_write.c
*/

#include "save_impl.h"

#include <fcntl.h>
#include <unistd.h>

void save_write(void)
{
    int fd = open(SAVE_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1)
        return;
    save_write_u32(fd, STATE.has_red_pot);
    save_write_char(fd, '\n');
    save_write_u32(fd, STATE.has_blue_pot);
    close(fd);
}
