/*
** EPITECH PROJECT, 2022
** grep
** File description:
** Implementation of grep
*/

#include "grep.h"
#include <stdlib.h>
#include "reader.h"
#include "my.h"

static int print_error(reader_t *reader)
{
    my_putstr_err("grep: ");
    my_putstr_err(reader->path);
    my_putstr_err(": ");
    switch (reader->error) {
        case 1:
        case 13: my_putstr_err("Permission denied"); break;
        case 2: my_putstr_err("No such file or directory"); break;
        case 21: my_putstr_err("File is a directory"); break;
        default: my_putstr_err("Unknown error");
    }
    my_putstr_err("\n");
    reader->error = 0;
    return 84;
}

int grep(char const *token, char const *path)
{
    reader_t reader;

    reader_create(&reader, path);
    if (reader.error)
        return print_error(&reader);
    while (!reader.end && !reader.error) {
        char *line = reader_getline(&reader);
        if (my_strstr(line, token) != 0)
            my_putstr(line);
        free(line);
    }
    reader_destroy(&reader);
    return reader.error ? print_error(&reader) : 0;
}

int grep_stdin(char const *token)
{
    reader_t reader;

    reader_create_stdin(&reader);
    if (reader.error)
        return print_error(&reader);
    while (!reader.end && !reader.error) {
        char *line = reader_getline(&reader);
        if (my_strstr(line, token) != 0)
            my_putstr(line);
        free(line);
    }
    reader_destroy(&reader);
    return reader.error ? print_error(&reader) : 0;
}
