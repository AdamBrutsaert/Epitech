/*
** EPITECH PROJECT, 2023
** reader_error_open.c
** File description:
** reader_error_open.c
*/

#include "asm/reader_impl.h"
#include "my/stdio.h"

void reader_error_open(const char *path)
{
    my_eputcs("error: reader: cannot open file '");
    my_eputcs(path);
    my_eputcs("'.\n");
}
