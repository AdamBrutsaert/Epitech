/*
** EPITECH PROJECT, 2022
** rush3.c
** File description:
** Implementation of rush3.c
*/

#include "rush3.h"
#include "my.h"
#include <unistd.h>
#include <stdlib.h>

static char *read_stdin(int *error)
{
    unsigned int length = 0;
    unsigned int capacity = 16;
    char *str = malloc(capacity);
    int bytes = read(0, str + length, capacity - length);

    while (bytes > 0) {
        length += bytes;
        if (length == capacity) {
            capacity *= 2;
            str = my_realloc(str, capacity, length);
        }
        bytes = read(0, str + length, capacity - length);
    }
    if (bytes < 0)
        *error = 84;
    str[length] = '\0';
    return str;
}

int rush3(void)
{
    int error = 0;
    int width;
    int height;
    char *str = read_stdin(&error);
    char *tokens = 0;

    if (!error)
        tokens = parse(str, &width, &height);
    detect(tokens, width, height);
    free(str);
    free(tokens);
    return error;
}
