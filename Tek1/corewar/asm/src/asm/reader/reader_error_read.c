/*
** EPITECH PROJECT, 2023
** reader_error_read.c
** File description:
** reader_error_read.c
*/

#include "asm/reader_impl.h"
#include "my/stdio.h"

void reader_error_read(const char *path)
{
    my_eputcs("error: reader: cannot read file '");
    my_eputcs(path);
    my_eputcs("'.\n");
}
