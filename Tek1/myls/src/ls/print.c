/*
** EPITECH PROJECT, 2022
** print.c
** File description:
** print.c
*/

#include "my/details/ls.h"
#include "my/stdio.h"
#include <time.h>
#include <unistd.h>

static void print_permission(file_t *file)
{
    my_printc(file->permission & FILE_PERMISSION_UR ? 'r' : '-');
    my_printc(file->permission & FILE_PERMISSION_UW ? 'w' : '-');
    if (file->permission & FILE_PERMISSION_UID)
        my_printc(file->permission & FILE_PERMISSION_UX ? 's' : 'S');
    else
        my_printc(file->permission & FILE_PERMISSION_UX ? 'x' : '-');
    my_printc(file->permission & FILE_PERMISSION_GR ? 'r' : '-');
    my_printc(file->permission & FILE_PERMISSION_GW ? 'w' : '-');
    if (file->permission & FILE_PERMISSION_GID)
        my_printc(file->permission & FILE_PERMISSION_GX ? 's' : 'S');
    else
        my_printc(file->permission & FILE_PERMISSION_GX ? 'x' : '-');
    my_printc(file->permission & FILE_PERMISSION_OR ? 'r' : '-');
    my_printc(file->permission & FILE_PERMISSION_OW ? 'w' : '-');
    if (file->permission & FILE_PERMISSION_STICKY)
        my_printc(file->permission & FILE_PERMISSION_OX ? 't' : 'T');
    else
        my_printc(file->permission & FILE_PERMISSION_OX ? 'x' : '-');
    my_printc(' ');
}

static void print_size_or_device(file_t *file)
{
    if (file->type == FILE_TYPE_BLOCK_DEVICE
        || file->type == FILE_TYPE_CHARACTER_DEVICE) {
        my_putunbr(file->dev_major);
        my_prints(", ");
        my_putunbr(file->dev_minor);
    } else {
        my_putunbr(file->size);
    }
    my_printc(' ');
}

static void print_name(file_t *file)
{
    my_prints(file->name);
    if (file->type == FILE_TYPE_SYMBOLIC_LINK) {
        my_prints(" -> ");
        my_prints(file->symlink);
    }
    my_printc('\n');
}

void print_file(file_t *file, int8_t long_listing)
{
    if (!long_listing) {
        my_prints(file->name);
        my_printc('\n');
    } else {
        my_printc(file->type);
        print_permission(file);
        my_putunbr(file->links);
        my_printc(' ');
        my_prints(file->owner);
        my_printc(' ');
        my_prints(file->group);
        my_printc(' ');
        print_size_or_device(file);
        write(STDOUT_FILENO, ctime(&file->last_modification) + 4, 12);
        my_printc(' ');
        print_name(file);
    }
}

void print_directory(char const *name, file_vector_t *files, int8_t all,
    int8_t long_listing)
{
    int total = 0;

    for (uint64_t i = 0; i < files->length; i++)
        if (!(!all && *files->files[i].name == '.'))
            total += files->files[i].blocks;
    if (name) {
        my_prints(name);
        my_prints(":\n");
    }
    if (long_listing) {
        my_prints("total ");
        my_putunbr(total / 2);
        my_printc('\n');
    }
    for (uint64_t i = 0; i < files->length; i++) {
        if (!(!all && *files->files[i].name == '.'))
            print_file(&files->files[i], long_listing);
    }
}
