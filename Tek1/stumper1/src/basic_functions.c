/*
** EPITECH PROJECT, 2023
** B-CPE-210-stumper-adam.brutsaert
** File description:
** main.c
*/

#include "main.h"
#include "my/string.h"

#include <stdint.h>

char *double_buffer(char *buffer, uint64_t current_capacity)
{
    char *copy = malloc(sizeof(char) * current_capacity * 2 + 1);

    if (copy == NULL)
        return NULL;
    for (uint64_t i = 0; i < current_capacity; i++)
        copy[i] = buffer[i];
    free(buffer);
    return copy;
}

char *read_file(int fd)
{
    char *buff = malloc(sizeof(char) * 1024);
    int64_t read_bytes = 0;
    int64_t read_total = 0;
    int64_t capacity = 1024;

    if (buff == NULL)
        return NULL;
    do {
        read_total += read_bytes;
        if (read_total == capacity) {
            buff = double_buffer(buff, capacity);
            capacity *= 2;
        }
        if (buff == NULL)
            return NULL;
        read_bytes = read(fd, buff + read_total, capacity - read_total);
    } while (read_bytes > 0);
    buff[read_total] = '\0';
    return buff;
}

char *open_file(char const *src)
{
    int fd = 0;
    char *buff;

    if (my_strcmp(src, "-") != 0)
        fd = open(src, O_RDONLY);
    if (fd == -1) {
        my_puterr("head: cannot open '");
        my_puterr(src);
        my_puterr("' for reading: No such file or directory\n");
        return NULL;
    }
    buff = read_file(fd);
    close(fd);
    return buff;
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

void my_puterr(char *str)
{
    write(2, str, my_strlen(str));
}
