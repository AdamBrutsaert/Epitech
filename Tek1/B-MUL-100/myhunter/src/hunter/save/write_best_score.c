/*
** EPITECH PROJECT, 2022
** write_best_score.c
** File description:
** write_best_score.c
*/

#include "hunter.h"
#include "my.h"
#include <fcntl.h>
#include <unistd.h>

static char *u64_to_str(uint64_t nb)
{
    char *str = my_calloc(10);

    for (uint64_t i = 9; i; i--) {
        str[i - 1] = '0' + nb % 10;
        nb /= 10;
    }
    return str;
}

void write_best_score(uint64_t score)
{
    char *str = u64_to_str(score);
    int fd = open("save", O_WRONLY | O_CREAT, 0644);

    if (fd >= 0) {
        write(fd, str, 9);
        close(fd);
    }
    my_free(str);
}
