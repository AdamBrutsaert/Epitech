/*
** EPITECH PROJECT, 2022
** reader2
** File description:
** Implementation of reader2
*/

#include <stdlib.h>
#include "reader.h"
#include "my.h"

char reader_getchar(reader_t *reader)
{
    char c = reader->buffer[reader->index++];

    if (reader->index == reader->length)
        read_some(reader);
    return c;
}

char *reader_getline(reader_t *reader)
{
    long capacity = 8;
    long length = 0;
    char *str = malloc(capacity * sizeof(char));
    char *temp;

    while (!reader->end && !reader->error) {
        str[length++] = reader_getchar(reader);
        if (length == capacity) {
            capacity *= 2;
            temp = malloc(capacity * sizeof(char));
            my_memmove(temp, str, length);
            free(str);
            str = temp;
        }
        if (str[length - 1] == '\n')
            break;
    }
    str[length] = '\0';
    return str;
}
