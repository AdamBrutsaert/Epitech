/*
** EPITECH PROJECT, 2022
** read_best_score.c
** File description:
** read_best_score.c
*/

#include "hunter.h"
#include "my.h"
#include <unistd.h>
#include <fcntl.h>

static uint64_t str_to_u64(char *string)
{
    uint64_t result = 0;

    for (; *string >= '0' && *string <= '9'; string++)
        result = result * 10 + (*string - '0');
    return result;
}

uint64_t read_best_score(void)
{
    int fd = open("save", O_RDONLY);
    uint64_t result = 0;
    uint64_t bytes_read = 0;
    uint64_t score = 0;
    char *string = my_calloc(10);

    if (fd >= 0) {
        do {
            bytes_read += result;
            result = read(fd, string + bytes_read, 9 - bytes_read);
        } while (result > 0 && bytes_read < 9);
        close(fd);
        score = str_to_u64(string);
    }
    my_free(string);
    return score;
}
