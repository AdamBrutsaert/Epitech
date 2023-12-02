/*
** EPITECH PROJECT, 2022
** cat
** File description:
** Implementation of cat
*/

#include "cat.h"
#include "reader.h"
#include "my.h"

static int print_error(reader_t *reader)
{
    my_putstr_err("cat: ");
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

int cat(char const *path)
{
    reader_t reader;

    reader_create(&reader, path);
    if (reader.error)
        return print_error(&reader);
    reader_print(&reader);
    reader_destroy(&reader);
    return reader.error ? print_error(&reader) : 0;
}

int cat_stdin(void)
{
    reader_t reader;

    reader_create_stdin(&reader);
    if (reader.error)
        return print_error(&reader);
    reader_print(&reader);
    reader_destroy(&reader);
    return reader.error ? print_error(&reader) : 0;
}
