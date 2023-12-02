/*
** EPITECH PROJECT, 2022
** process.c
** File description:
** process.c
*/

#include "my/details/ls.h"
#include "my/stdio.h"
#include "my/string.h"

#include <stdlib.h>

static void process_recursion(char const *name, file_vector_t *vector,
    flags_t flags)
{
    file_t file;
    char *path;

    for (uint64_t i = 0; i < vector->length; i++) {
        if (vector->files[i].type == FILE_TYPE_DIRECTORY
            && my_strcmp(vector->files[i].name, ".")
            && my_strcmp(vector->files[i].name, "..")) {
            path = get_path(name, vector->files[i].name);
            file_get(&file, path, vector->files[i].name);
            process_directory(&file, flags, 1, 1);
            free(path);
        }
    }
}

static int8_t is_there_a_directory(file_vector_t *vector)
{
    for (uint64_t i = 0; i < vector->length; i++)
        if (vector->files[i].type == FILE_TYPE_DIRECTORY
            && my_strcmp(vector->files[i].name, ".")
            && my_strcmp(vector->files[i].name, ".."))
            return 1;
    return 0;
}

// TODO if -R and there is a folder inside vector, then show_name must be one
int32_t process_directory(file_t *file, flags_t flags, int8_t prefix,
    int8_t show_name)
{
    file_vector_t vector;
    int error = 0;

    file_vector_create(&vector);
    if (file_read_directory(&vector, file->path)) {
        file_vector_destroy(&vector);
        return 84;
    }
    file_vector_sort(&vector, flags & FLAG_SORT_TIME,
        flags & FLAG_SORT_REVERSE);
    if (prefix)
        my_printc('\n');
    show_name += flags & FLAG_RECURSIVE && is_there_a_directory(&vector);
    print_directory(show_name ? file->path : 0, &vector, flags & FLAG_ALL,
        flags & FLAG_LONG_LISTING);
    if (flags & FLAG_RECURSIVE)
        process_recursion(file->path, &vector, flags);
    file_vector_destroy(&vector);
    return error;
}

void process_file(file_t *file, flags_t flags)
{
    print_file(file, flags & FLAG_LONG_LISTING);
}
